#include "parser.h"
#include <iostream>

Parser::Parser(){
	this->reset();
	m_pLogger = new Logger();
};

void Parser::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
};

void Parser::reset(){
	m_bCommandCompleted = false;
	m_strCommandName = "";
	m_listCode.clear();
	m_listSingleLineCommands
		<< "draw"
		<< "wait"
		<< "line"
		<< "rect"
		<< "pixel";
};

void Parser::parse(QString code){
	QStringList list = code.split("\n");
	for(int i = 0; i < list.size(); i ++){
		this->parseLine(list.at(i));
	}
}

void Parser::parseLine(QString line){
	line = removeComment(line);
	if(line.length() > 0){
		m_listCode << line;
		QStringList list = line.split(" ");
		QString strName = list[0];
		list.removeAt(0);
		if(m_listSingleLineCommands.contains(strName)){
			m_bCommandCompleted = true;
			Command command;
			command.setName(strName);
			command.setParams(list);
			m_vCommands.push_back(command);
		}else{
			m_pLogger->warn("'" + strName + "' skip (Unknown command)");
		}
	}
};

bool Parser::hasCommand(){
	return m_vCommands.size() > 0;
};

Command Parser::command(){
	Command command;
	if(m_vCommands.size() > 0){
		command = m_vCommands.first();
		m_vCommands.pop_front();
	}
	return command;
};

bool Parser::isCommandCompleted(){
	return m_bCommandCompleted;
};

QString Parser::removeComment(QString line){
	int pos = line.indexOf("#");
	// std::cout << pos;
	if(pos >= 0)
		line.remove(pos, line.length() - pos);
	line = line.trimmed();
	return line;
}


/*const QString str = QLatin1String("AA110011");
bool ok;
const unsigned int parsedValue = str.toUInt(&ok, 16);
if (!ok) {
    //Parsing failed, handle error here
}*/
