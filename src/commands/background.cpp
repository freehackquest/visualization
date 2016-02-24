#include "background.h"
#include <iostream>
#include <QString>

CommandBackground::CommandBackground(){
};

bool CommandBackground::isMultiLine(){
	return false;
};

ICommand *CommandBackground::create(){
	return new CommandBackground();
};

QString CommandBackground::name(){
	return "background";
};

/*
 * @command background <color>
 * @author Evgenii Sopov
 * @usage fix
 * @descr fixing frame and output
 * */
void CommandBackground::setParams(QStringList list){
	m_listParams << list;
	QString sUsage = " Usage: 'background <color>'";
	m_bCheck = true;
	if(list.size() != 1){
		m_sCheck = "Expected 1 params. " + sUsage;
		m_bCheck = false;
		return;
	}
	bool bConvert = false;
	m_nColor = m_listParams[0].toInt(&bConvert,16);
	if(!bConvert){
		m_sCheck = "Parameter color must be hex. " + sUsage;
		m_bCheck = false;
		return;
	}
};

bool CommandBackground::check(){
	return m_bCheck;
};

bool CommandBackground::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandBackground::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandBackground::appendCode(QString){
	// this command is single line
};

void CommandBackground::run(ICore *pCore){
	/*for(int y = 0; y < pFrame->height(); y++){
		for(int x = 0; x < pFrame->width(); x++){
			pFrame->setPixel(x,y,m_nColor);
		}
	}*/
};

