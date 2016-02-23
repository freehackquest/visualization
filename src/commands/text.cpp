#include "text.h"
#include <iostream>
#include <QString>

CommandText::CommandText(){
};

bool CommandText::isMultiLine(){
	return false;
};

ICommand *CommandText::create(){
	return new CommandText();
};
	
QString CommandText::name(){
	return "text";
};

/*
 * @command line
 * @author Evgenii Sopov
 * @usage text <x1> <y1> <color> <text>
 * @param x1 - requared, integer
 * @param y1 - requared, integer
 * @param text - requared, string
 * */

void CommandText::setParams(QStringList list){
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
	QString sUsage = " Usage: 'text <x1> <y1> <color> <text>'"; 
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
		m_sCheck = "Parameter color must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	QString m_sText = m_listParams[3];
};

bool CommandText::check(){
	return m_bCheck;
};

bool CommandText::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandText::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandText::appendCode(QString){
	// this command is single line
};

void CommandText::run(QVector<QImage *> &vFrames){
	if(!m_bCheck) return;

};

