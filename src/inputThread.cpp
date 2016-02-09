
#include "inputThread.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>


InputThread::InputThread(){
	m_pParser = new Parser();
	m_pLogger = new Logger();
};

void InputThread::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
	m_pParser->setLogger(pLogger);
};

bool InputThread::hasCommand(){
	QMutexLocker lock(&m_Mutex);
	return m_vCommands.size() > 0;
};

ICommand *InputThread::command(){
	QMutexLocker lock(&m_Mutex);
	if(m_vCommands.size() > 0){
		ICommand *pCommand = m_vCommands.first();
		m_vCommands.pop_front();
		return pCommand;
	}
	return NULL;
};

void InputThread::pushCommand(ICommand *pCommand){
	QMutexLocker lock(&m_Mutex);
	m_vCommands.push_back(pCommand);
	// m_pLogger->debug("PUSHED COMMAND: " + pCommand->code());
};

void InputThread::run(){
	m_pLogger->info("Input Thread Started");
	for (std::string line; std::getline(std::cin, line);) {
		QString sLine(line.c_str());
		m_pParser->parse(sLine);
		while(m_pParser->hasCommand()){
			pushCommand(m_pParser->command());
		}
	}
};
