
#include "outputStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QTcpServer>
		
OutputStream::OutputStream(){
	m_pLogger = new Logger();
};

void OutputStream::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
};

void OutputStream::setParams(QVector<QString> &params){
	int nWidth = 1280;
	int nHeight = 720;

	{
		int n = params.indexOf("--width");
		if(n > 0 && n+1 < params.size()){
			nWidth = params[n+1].toInt();
		}
	}

	{
		int n = params.indexOf("--height");
		if(n > 0 && n+1 < params.size()){
			nHeight = params[n+1].toInt();
		}
	}

	m_pFrame = new Frame(nWidth, nHeight);
	m_pDrawObjectsCollection = new DrawObjectsCollection();
};

void OutputStream::setInputStream(InputStreamCommands *pInputStreamCommands){
	m_pInputStreamCommands = pInputStreamCommands;
};

void OutputStream::run(){
	while(true){
		while(m_pInputStreamCommands->hasCommand()){
			ICommand *pCommand = m_pInputStreamCommands->command();
			pCommand->run(m_pFrame, m_pDrawObjectsCollection);
			m_pLogger->debug("Executed " + pCommand->code());
		}
		QThread::msleep(200);
		m_pFrame->outputToStd();
	};
};
