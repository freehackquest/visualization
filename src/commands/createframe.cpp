#include "createframe.h"
#include <iostream>
#include <QString>

CommandCreateFrame::CommandCreateFrame(){
	m_sCheck = "";
	m_bCheck = true;
};

bool CommandCreateFrame::isMultiLine(){
	return false;
};

ICommand *CommandCreateFrame::create(){
	return new CommandCreateFrame();
};
	
QString CommandCreateFrame::name(){
	return "createframe";
};

/*
 * @MANUAL START
 * @command createframe
 * @author Evgenii Sopov <mrseakg@gmail.com>
 * @usage createframe
 * @description Created a new empty frame.
 * @MANUAL STOP
 * */

void CommandCreateFrame::setParams(QStringList list){
	m_listParams << list;
};

bool CommandCreateFrame::check(){
	return m_bCheck;
};

bool CommandCreateFrame::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandCreateFrame::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandCreateFrame::appendCode(QString){
	// this command is single line
};

void CommandCreateFrame::run(ICore *pCore){
	if(!m_bCheck) return;
	pCore->createFrame();
};

