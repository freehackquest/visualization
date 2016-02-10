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
 * @author John Doe
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

void CommandLine::run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection){
	if(!m_bCheck) return;
	
	int diffX = m_nX2 - m_nX1;
	int diffY = m_nY2 - m_nY1;
	double dX = 0;
	double dY = 0;
	int nLength = 0;

	if(std::abs(diffX) > std::abs(diffY)){
		dX = diffX < 0 ? -1 : 1;
		dY = double(diffY)/double(diffX);
		dY = diffY < 0 ? dY : -1*dY;
		nLength = std::abs(diffX);
	}else{
		dX = double(diffX)/double(diffY);
		dX = diffX < 0 ? -1*dX : dX;
		dY = diffY < 0 ? -1 : 1;
		nLength = std::abs(diffY);
	}

	double x = m_nX1;
	double y = m_nY1;
	for(int i = 0; i < nLength; i++){
		x=x+dX;
		y=y+dY;
		pFrame->setPixel(int(x),int(y),m_nColor);
	}
};

