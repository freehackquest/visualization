#include "draw.h"
#include <iostream>
#include <QString>

CommandDraw::CommandDraw(){
};

bool CommandDraw::isMultiLine(){
	return false;
};

ICommand *CommandDraw::create(){
	return new CommandDraw();
};
	
QString CommandDraw::name(){
	return "draw";
};

void CommandDraw::setParams(QStringList list){
	m_listParams << list;
};

bool CommandDraw::check(){
	return true;
};

bool CommandDraw::check(QString &strResult){
	strResult = "OK";
	return true;
};

QString CommandDraw::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandDraw::appendCode(QString){
	// this command is single line
}

void CommandDraw::run(ICore *pCore){
	
}
