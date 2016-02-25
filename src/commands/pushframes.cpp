#include "pushframes.h"
#include <iostream>
#include <QString>

CommandPushFrames::CommandPushFrames(){
};

bool CommandPushFrames::isMultiLine(){
	return false;
};

ICommand *CommandPushFrames::create(){
	return new CommandPushFrames();
};
	
QString CommandPushFrames::name(){
	return "pushframes";
};

/*
 * @command pushframes
 * @author Evgenii Sopov
 * @usage pushframes
 * @descr fixing frames and output
 * */
void CommandPushFrames::setParams(QStringList list){
	QString sUsage = " Usage: 'pushframes'";
	m_bCheck = true;
	if(list.size() != 0){
		m_sCheck = "Expected 0 params. " + sUsage;
		m_bCheck = false;
		return;
	}
};

bool CommandPushFrames::check(){
	return m_bCheck;
};

bool CommandPushFrames::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandPushFrames::code(){
	return name();
}

void CommandPushFrames::appendCode(QString){
	// Nothing it's single line command
}

void CommandPushFrames::run(ICore *pCore){
	pCore->pushFrames();
}
