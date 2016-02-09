#include "parser.h"
#include <iostream>

Parser::Parser(){
	m_pLogger = new Logger();
	m_pCommandsCollection = new CommandsCollection();
	m_bMultiLineCommand = false;
};

void Parser::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
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
		QStringList list = line.split(" ");
		QString strName = list[0];
		if(m_bMultiLineCommand == true && list.size() == 2){
			if(list[0] == m_pTemporaryCommand->name() && list[1] == "end"){
				m_bMultiLineCommand = false;
				m_vCommands.push_back(m_pTemporaryCommand);
			}else{
				m_pTemporaryCommand->appendCode(line);
			}
		}else if(m_bMultiLineCommand == true){
				m_pTemporaryCommand->appendCode(line);
		}else if(m_pCommandsCollection->contains(strName)){
			m_bMultiLineCommand = m_pCommandsCollection->isMultiLine(strName);
			m_pTemporaryCommand = m_pCommandsCollection->create(strName);
			
			list.removeAt(0);
			m_pTemporaryCommand->setParams(list);
			QString sCheck = "";
			if(!m_pTemporaryCommand->check(sCheck)){
				m_pLogger->error("'" + strName + "'" + sCheck);
			}

			if(!m_bMultiLineCommand){
				m_vCommands.push_back(m_pTemporaryCommand);
			}
		}else{
			m_pLogger->warn("'" + strName + "' unknown command, skipped");
		}
	}
};

bool Parser::hasCommand(){
	return m_vCommands.size() > 0;
};

ICommand *Parser::command(){
	if(m_vCommands.size() > 0){
		ICommand *pCommand = m_vCommands.first();
		m_vCommands.pop_front();
		return pCommand;
	}
	return NULL;
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
