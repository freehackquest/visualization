#include "countdown.h"
#include <iostream>
#include <QString>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QPainter>

CommandCountDown::CommandCountDown(){
	m_sCheck = "";
	m_bCheck = true;
};

CommandCountDown::~CommandCountDown(){
};

bool CommandCountDown::isMultiLine(){
	return false;
};

ICommand *CommandCountDown::create(){
	return new CommandCountDown();
};
	
QString CommandCountDown::name(){
	return "countdown";
};

/*
 * @MANUAL START
 * @command countdown
 * @author Evgenii Sopov
 * @usage countdown <seconds> <finishtext>
 * @param seconds - required; integer; min: 0; max: 360 (5 minutes)
 * @param finishtext - string, show text after finish countdown
 * @example countdown 5 "Round #14"
 * @MANUAL STOP
 * */

void CommandCountDown::setParams(QStringList list){
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
	QString sUsage = " Usage: 'countdown <seconds> <finishtext>'"; 
	if(m_listParams.size() != 2){
		m_sCheck = "Expected 2 params. " + sUsage;
		m_bCheck = false;
		return;
	}
	bool bConvert = false;
	m_nSeconds = m_listParams[0].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter seconds must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	if(m_nSeconds < 0){
		m_sCheck = "Parameter seconds must be positive. " + sUsage;
		m_bCheck = false;
	}

	if(m_nSeconds > 360){
		m_sCheck = "Parameter seconds must be not more 360. " + sUsage;
		m_bCheck = false;
	}
	
	m_sFinishText = m_listParams[1];
};

bool CommandCountDown::check(){
	return m_bCheck;
};

bool CommandCountDown::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandCountDown::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandCountDown::appendCode(QString){
	// this command is single line
};

void CommandCountDown::run(ICore *pCore){
	if(!m_bCheck) return;
	int nWidth = pCore->width();
	int nHeight = pCore->height();
	int nFrameRate = pCore->framerate();

	int id = QFontDatabase::addApplicationFont(":/fonts/hack.regular.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont font(family, 120);

	QFontMetrics fm(font);
	QString text = "00:00";
	int nTextWidth = fm.width(text);
	int nTextHeight = fm.height();
	int nTextX = nWidth/2 - nTextWidth/2;
	int nTextY = nHeight/2 + nTextHeight/2 - 25;
	int nArcWidth = nTextWidth+70;
	
	QRect rect(nWidth/2 - nArcWidth/2, nHeight/2 - nArcWidth/2, nArcWidth, nArcWidth);
	QPen pen(QColor(0xFFC8C8C8));
	pen.setWidth(25);

	bool bVector = false;
	for(int fr = 0; fr <= m_nSeconds*nFrameRate; fr++){
		int nCurrentValue = (m_nSeconds - fr / nFrameRate) - 1;
		nCurrentValue = nCurrentValue < 0 ? 0 : nCurrentValue;
		int m = (nCurrentValue - nCurrentValue%60)/60;
		int s = nCurrentValue%60;
		text = (m < 10 ? "0" : "") + QString::number(m) + ":" + (s < 10 ? "0" : "") + QString::number(s);

		QImage *pFrame = pCore->createFrame();
		QPainter p(pFrame);
		// p.setPen(QPen(QColor(0x00C8C8C8)));
		// p.setBrush(QBrush(QColor(0xFFC8C8C8)));
		p.setFont(font);
		p.setPen(pen);

		p.drawText(nTextX, nTextY, text);

		if(fr % nFrameRate == 0){
			bVector = !bVector;
		}
		int nStartAngle = 0;
		int nSpanAngle = double(360*16);
		if(bVector){
			nSpanAngle = (double(fr % nFrameRate) / double(nFrameRate)) * double(360*16);
		}else{
			nStartAngle = (double(fr % nFrameRate) / double(nFrameRate)) * double(360*16);
			nSpanAngle = double(360*16) - nStartAngle;
		}

		p.drawArc(rect, nStartAngle, nSpanAngle);
		p.end();
		if (fr > 0 && fr % (2*nFrameRate) == 0){
			pCore->pushFrames();
		}
	}
	
	pCore->pushFrames();
};

