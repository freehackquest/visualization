#include "skip.h"
#include <iostream>
#include <QString>

CommandSkip::CommandSkip(){
};

bool CommandSkip::isMultiLine(){
	return false;
};

ICommand *CommandSkip::create(){
	return new CommandSkip();
};
	
QString CommandSkip::name(){
	return "skip";
};

/*
 * @command skip
 * @author Evgenii Sopov
 * @usage skip <number>
 * @param number requared, integer
 * @descr skip frames
 * */
void CommandSkip::setParams(QStringList list){
	m_listParams << list;
	QString sUsage = " Usage: 'skip <number>'";
	m_bCheck = true;
	if(list.size() != 1){
		m_sCheck = "Expected 0 params. " + sUsage;
		m_bCheck = false;
		return;
	}
	
	bool bConvert = false;
	m_nCount = list[0].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter number must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	if(m_nCount < 1){
		m_sCheck = "Parameter number must be more then 0. " + sUsage;
		m_bCheck = false;
		return;
	}
};

bool CommandSkip::check(){
	return m_bCheck;
};

bool CommandSkip::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandSkip::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandSkip::appendCode(QString){
	// this command is single line
}

void CommandSkip::run(Frame *pFrame, DrawObjectsCollection *){
	for(int i = 0; i < m_nCount; i++){
		pFrame->outputToStd();
	}
}
