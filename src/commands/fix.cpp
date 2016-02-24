#include "fix.h"
#include <iostream>
#include <QString>

CommandFix::CommandFix(){
};

bool CommandFix::isMultiLine(){
	return false;
};

ICommand *CommandFix::create(){
	return new CommandFix();
};
	
QString CommandFix::name(){
	return "fix";
};

/*
 * @command fix
 * @author Evgenii Sopov
 * @usage fix
 * @descr fixing frame and output
 * */
void CommandFix::setParams(QStringList list){
	QString sUsage = " Usage: 'fix'";
	m_bCheck = true;
	if(list.size() != 0){
		m_sCheck = "Expected 0 params. " + sUsage;
		m_bCheck = false;
		return;
	}
};

bool CommandFix::check(){
	return m_bCheck;
};

bool CommandFix::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandFix::code(){
	return name();
}

void CommandFix::appendCode(QString){
	// Nothing it's single line command
}

void CommandFix::run(ICore *pCore){
}
