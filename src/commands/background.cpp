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

void CommandBackground::setParams(QStringList list){
	m_listParams << list;
};

bool CommandBackground::check(){
	return true;
};

bool CommandBackground::check(QString &strResult){
	strResult = "OK";
	return true;
};

QString CommandBackground::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandBackground::appendCode(QString){
	// this command is single line
};

void CommandBackground::run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection){
};

