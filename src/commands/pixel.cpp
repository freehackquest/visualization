#include "pixel.h"
#include <iostream>
#include <QString>

CommandPixel::CommandPixel(){
};

bool CommandPixel::isMultiLine(){
	return false;
};

ICommand *CommandPixel::create(){
	return new CommandPixel();
};
	
QString CommandPixel::name(){
	return "pixel";
};

/*
 * @command pixel
 * @author Evgenii Sopov
 * @usage pixel <x1> <y1> <color>
 * @param x1 requared, integer
 * @param y1 - requared, integer
 * @param color - requared, color
 * */
void CommandPixel::setParams(QStringList list){
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
	QString sUsage = " Usage: 'line <x1> <y1> <color>'"; 
	if(m_listParams.size() != 3){
		m_sCheck = "Expected 3 params. " + sUsage;
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
	m_nColor = m_listParams[2].toInt(&bConvert,16);
	if(!bConvert){
		m_sCheck = "Parameter color must be hex. " + sUsage;
		m_bCheck = false;
		return;
	}
};

bool CommandPixel::check(){
	return m_bCheck;
};

bool CommandPixel::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandPixel::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandPixel::appendCode(QString){
	// Nothing it's single line command
}

void CommandPixel::run(QVector<QImage *> &vFrames){

}
