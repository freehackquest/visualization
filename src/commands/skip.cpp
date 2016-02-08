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

void CommandSkip::setParams(QStringList list){
	m_listParams << list;
};

bool CommandSkip::check(){
	return true;
};

bool CommandSkip::check(QString &strResult){
	strResult = "OK";
	return true;
};

QString CommandSkip::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandSkip::appendCode(QString){
	// this command is single line
}

void CommandSkip::run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection){
	
}
