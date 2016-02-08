#include "table.h"
#include <iostream>
#include <QString>

CommandTable::CommandTable(){
};

bool CommandTable::isMultiLine(){
	return true;
};

ICommand *CommandTable::create(){
	return new CommandTable();
};
	
QString CommandTable::name(){
	return "table";
};

void CommandTable::setParams(QStringList list){
	m_listParams << list;
};

bool CommandTable::check(){
	return true;
};

bool CommandTable::check(QString &strResult){
	strResult = "OK";
	return true;
};

QString CommandTable::code(){
	return name() + " " + m_listParams.join(" ") + "\n\t" + m_strCode.join("\n\t") + "\n" + name() + " end";
}

void CommandTable::appendCode(QString line){
	m_strCode << line;
}

void CommandTable::run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection){
	
}
