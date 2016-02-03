#include "command.h"
#include <iostream>
#include <QString>

Command::Command(){
};

void Command::setName(QString name){
	m_strName = name;
};

void Command::setParams(QStringList list){
	m_listParams << list;
};

bool Command::check(){
};

bool Command::check(QString &strResult){
	return true;
};

QString Command::toString(){
	return m_strName + " " + m_listParams.join(" ");
}
