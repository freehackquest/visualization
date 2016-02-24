
#include "renderStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>

RenderStream::RenderStream(ICore *pCore){
	m_pCore = pCore;
	m_pLogger = m_pCore->logger();
	m_pInputStreamCommands = NULL;
	m_pOutputStream = NULL;
	m_pLogger->info("RenderStream created");
};

void RenderStream::setInputStream(InputStreamCommands *pInputStreamCommands){
	m_pLogger->info("RenderStream <- InputStreamCommands");
	m_pInputStreamCommands = pInputStreamCommands;
};

void RenderStream::setOutputStream(OutputStream *pOutputStream){
	m_pLogger->info("RenderStream -> OutputStream");
	m_pOutputStream = pOutputStream;
};

void RenderStream::run(){
	m_pLogger->info("RenderStream started");
	while(true){
		if(m_pInputStreamCommands == NULL || m_pOutputStream == NULL) {
			m_pLogger->error("InputStreamCommands or OutputStream is null");
			return;
		}
		while(m_pInputStreamCommands->hasCommand()){
			ICommand *pCommand = m_pInputStreamCommands->command();
			pCommand->run(m_pCore);
			m_pLogger->debug("Executed " + pCommand->code());
		}
		QThread::msleep(1000/m_pCore->framerate());
	};
};
