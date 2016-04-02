#include "fhqvisualization.h"
#include <iostream>
#include <QString>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QPainter>

CommandFHQVisualization::CommandFHQVisualization(){
	m_sCheck = "";
	m_bCheck = true;
};

CommandFHQVisualization::~CommandFHQVisualization(){
};

bool CommandFHQVisualization::isMultiLine(){
	return false;
};

ICommand *CommandFHQVisualization::create(){
	return new CommandFHQVisualization();
};
	
QString CommandFHQVisualization::name(){
	return "fhqvisualization";
};

/*
 * @MANUAL START
 * @command fhqvisualization
 * @description Scene of freehackquest Welcome
 * @author Evgenii Sopov <mrseakg@gmail.com>
 * @usage fhqvisualization
 * @youtube http://www.youtube.com/watch?v=UGPXa3HGj7w
 * @MANUAL STOP
 * */

void CommandFHQVisualization::setParams(QStringList list){
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
};

bool CommandFHQVisualization::check(){
	return m_bCheck;
};

bool CommandFHQVisualization::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandFHQVisualization::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandFHQVisualization::appendCode(QString){
	// this command is single line
};

void CommandFHQVisualization::run(ICore *pCore){
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

