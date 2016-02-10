
#include "inputStreamCommands.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QTcpServer>
		
InputStreamCommands::InputStreamCommands(QObject *parent) :
	QObject(parent) {
	m_pParser = new Parser();
	m_pLogger = new Logger();
};

void InputStreamCommands::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
	m_pParser->setLogger(pLogger);
};

bool InputStreamCommands::hasCommand(){
	QMutexLocker lock(&m_MutexCommand);
	return m_vCommands.size() > 0;
};

ICommand *InputStreamCommands::command(){
	QMutexLocker lock(&m_MutexCommand);
	if(m_vCommands.size() > 0){
		ICommand *pCommand = m_vCommands.first();
		m_vCommands.pop_front();
		return pCommand;
	}
	return NULL;
};

void InputStreamCommands::pushCommand(ICommand *pCommand){
	QMutexLocker lock(&m_MutexCommand);
	m_vCommands.push_back(pCommand);
	// m_pLogger->debug("PUSHED COMMAND: " + pCommand->code());
};

void InputStreamCommands::slotNewConnection(){
	m_pLogger->info("Client connected.");
	m_pTcpSocket = m_pTcpServer->nextPendingConnection();
	connect(m_pTcpSocket,SIGNAL(readyRead()),this, SLOT(slotReadClient()));
	// connect(pClientSocket, SIGNAL(disconnected()),pClientSocket, SLOT(deleteLater()));
	// send hello
	QTextStream os(m_pTcpSocket);
	os.setAutoDetectUnicode(true);
	os << "Welcome to visualization!\n";
};

void InputStreamCommands::pushCode(QString strCode){
	QMutexLocker lock(&m_MutexCode);
	m_pParser->parse(strCode);
	while(m_pParser->hasCommand()){
		pushCommand(m_pParser->command());
	}
};

void InputStreamCommands::slotReadClient(){
	QTextStream os(m_pTcpSocket);
	os.setAutoDetectUnicode(true);
	os << "OK\n";
	QString strCode = m_pTcpSocket->readAll();
	this->pushCode(strCode);
};

void InputStreamCommands::start(int nPort){
	m_pTcpServer = new QTcpServer();
    connect(m_pTcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
    if (!m_pTcpServer->listen(QHostAddress::Any, nPort)) {
		m_pLogger->error("Unable to start Input Server.");
		return;
    } else {
		m_pLogger->info("Input Server Started. Wait connection.");
    }
};

void InputStreamCommands::stop(){
	m_pTcpServer->close();
}
