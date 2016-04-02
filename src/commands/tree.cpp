#include "tree.h"
#include <iostream>
#include <QString>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QPainter>
#include <cmath>
#include <QTime>
#include <QThread>


CommandTree::CommandTree(){
	m_sCheck = "";
	m_bCheck = true;
};

CommandTree::~CommandTree(){
};

bool CommandTree::isMultiLine(){
	return false;
};

ICommand *CommandTree::create(){
	return new CommandTree();
};
	
QString CommandTree::name(){
	return "tree";
};

/*
 * @MANUAL START
 * @command tree
 * @description Show random tree
 * @author Evgenii Sopov
 * @usage tree
 * @youtube http://www.youtube.com/watch?v=jX01mF7GJPo
 * @MANUAL STOP
 * */

void CommandTree::setParams(QStringList list){
	m_listParams << list;
};

bool CommandTree::check(){
	return m_bCheck;
};

bool CommandTree::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandTree::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandTree::appendCode(QString){
	// this command is single line
};

struct TreeLine{
	TreeLine() {};
	TreeLine(int x1,int y1,int x2,int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
	int length(){
		double sum = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
		if(sum == 0) return 0;
		return std::sqrt(sum);
	};
	double angle(){
		double c = length();
		if(c == 0) return 0;
		double b = y2-y1;
		double a = x2-x1;
		double betta = asin(b/c);
		double alpha = asin(a/c);
		return a < 0 ? betta - 0.79 : betta;
	}
	int x1;
	int y1;
	int x2;
	int y2;
};

void recoursion(TreeLine line, QImage *pBaseFrame, ICore *pCore, int &nCounter){
	int len = line.length();
	if(len < 30) return;
	
	{
		QPainter p(pBaseFrame);
		QPen pen(QColor(0x00C8C8C8));
		pen.setWidth(len/30);
		p.setPen(pen);
		p.drawImage(QPoint(0, 0), *pBaseFrame);
		p.drawLine(line.x1, line.y1, line.x2, line.y2);
		p.end();
	}

	nCounter++;
	int nForksDraw = 30;
	if(nCounter%nForksDraw == 0){
		QImage *pFrame = pCore->createFrame();
		QPainter p(pFrame);
		p.drawImage(QPoint(0, 0), *pBaseFrame);
		p.end();

		if(nCounter%(nForksDraw*pCore->framerate()) == 0){
			pCore->pushFrames();
			QThread::msleep(500);
		}
	}

	int newLen = (len*0.77);

	int x1 = line.x2;
	int y1 = line.y2;
	int nForks = (len/60)+1;
	for(int a = 0; a < nForks; a++){
		double d = double(qrand()%158-79)/100;
		// pCore->logger()->debug(QString::number(line.angle()));
		int x2 = x1 + newLen*std::cos(line.angle() + d);
		int y2 = y1 + newLen*std::sin(line.angle() + d);
		TreeLine l(x1,y1,x2,y2);
		recoursion(l,pBaseFrame,pCore,nCounter);
	}
	
}

void CommandTree::run(ICore *pCore){
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
	if(!m_bCheck) return;
	int nWidth = pCore->width();
	int nHeight = pCore->height();
	QImage *pBaseFrame = new QImage(QSize(nWidth,nHeight), QImage::Format_RGB32);
	pBaseFrame->fill(QColor(0x303030));
	int nCounter = 0;
	TreeLine line(nWidth/2, nHeight - 40, nWidth/2, 2*(nHeight/3));
	recoursion(line,pBaseFrame,pCore,nCounter);
	QImage *pFrame = pCore->createFrame();
	QPainter p(pFrame);
	p.drawImage(QPoint(0, 0), *pBaseFrame);
	p.end();		
	pCore->pushFrames();
};

