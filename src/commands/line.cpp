#include "line.h"
#include <iostream>
#include <QString>

CommandLine::CommandLine(){
};

bool CommandLine::isMultiLine(){
	return false;
};

ICommand *CommandLine::create(){
	return new CommandLine();
};
	
QString CommandLine::name(){
	return "line";
};

/*
 * @command line
 * @author Evgenii Sopov
 * @usage line <x1> <y1> <x2> <y2> <width> <color>
 * @param x1 requared, integer
 * @param y1 - requared, integer
 * @param x2 - requared, integer
 * @param y2 - requared, integer
 * @param width - requared, positive and > 0, integer
 * @param color - requared, color
 * */

void CommandLine::setParams(QStringList list){
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
	QString sUsage = " Usage: 'line <x1> <y1> <x2> <y2> <width> <color>'"; 
	if(m_listParams.size() != 6){
		m_sCheck = "Expected 6 params. " + sUsage;
		m_bCheck = false;
		return;
	}
	bool bConvert = false;
	m_nX1 = m_listParams[0].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter x1 must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nY1 = m_listParams[1].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter y1 must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nX2 = m_listParams[2].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter x2 must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nY2 = m_listParams[3].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter y2 must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nWidth = m_listParams[4].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter width must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	if(m_nWidth < 1){
		m_sCheck = "Parameter width must be more then 0. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nColor = m_listParams[5].toInt(&bConvert,16);
	if(!bConvert){
		m_sCheck = "Parameter color must be hex. " + sUsage;
		m_bCheck = false;
		return;
	}
};

bool CommandLine::check(){
	return m_bCheck;
};

bool CommandLine::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandLine::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandLine::appendCode(QString){
	// this command is single line
};

int CommandLine::distance(int x1, int x2){
	if(x2 > x1)
		return x2-x1;
	return x1-x2;
}

void CommandLine::run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection){
	if(!m_bCheck) return;
	
	int nDistanceX = distance(m_nX2,m_nX1);
	int nDistanceY = distance(m_nY2,m_nY1);
	double nDX = 1;
	double nDY = 1;
	int nLength = 0;

	if(nDistanceX > nDistanceY){
		nDY = double(nDistanceY)/double(nDistanceX);
		nLength = nDistanceX;
	}else{
		nDX = double(nDistanceX)/double(nDistanceY);
		nLength = nDistanceY;
	}

	nDX = m_nX2 > m_nX1 ? nDX : -1*nDX;
	nDY = m_nY2 > m_nY1 ? nDY : -1*nDY;
		
	double x = m_nX1;
	double y = m_nY1;
	for(int i = 0; i < nLength; i++){
		x=x+nDX;
		y=y+nDY;
		pFrame->setPixel(int(x),int(y),m_nColor);
	}
};

