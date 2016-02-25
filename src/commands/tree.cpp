#include "tree.h"
#include <iostream>
#include <QString>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QPainter>

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
 * @command tree
 * @author Evgenii Sopov
 * @usage tree
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

void CommandTree::run(ICore *pCore){
	if(!m_bCheck) return;
	int nWidth = pCore->width();
	int nHeight = pCore->height();
	QImage imgLogo(":/images/fhq2015.png");
	int nWidthLogo = imgLogo.width();
	int nHeightLogo = imgLogo.width();

	int id = QFontDatabase::addApplicationFont(":/fonts/hack.regular.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont font(family, 24);

	QFontMetrics fm(font);
	QString text = "visualization";
	int nTextWidth = fm.width(text);
	int nTextHeight = fm.height();
	int nFinishXText = nWidth/2 - nTextWidth/2;
	
	int nFinishXLogo = (nWidth-nWidthLogo)/2;
	int nY = (nHeight-nHeightLogo)/2;

	int nFrames = 3*pCore->framerate();
	int nDiff = (nWidth - nFinishXLogo)/nFrames;
	int nDiffText = (nFinishXText + nTextWidth)/nFrames;
	for(int fr = 0; fr < nFrames; fr++){
		QImage *pFrame = pCore->createFrame();
		QPainter p(pFrame);
		p.setPen(QPen(QColor(0x00C8C8C8)));
		p.setBrush(QBrush(QColor(0x00C8C8C8)));
		int nX = (nWidth - nDiff*(fr+1));
		if (fr == nFrames-1)
			nX = nFinishXLogo;
		p.drawImage(QPoint(nX, nY), imgLogo);	
		p.setFont(font);
		p.setPen(QPen(QColor(0xFFC8C8C8)));

		int nXt = nDiffText*(fr+1) - nTextWidth;
		if (fr == nFrames-1){
			nXt = nFinishXText;
		}
		p.drawText(nXt, nY + 10 + nTextHeight + nHeightLogo, text);
		p.end();
	}
	pCore->pushFrames();
};

