
#include "renderStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>

RenderStream::RenderStream(){
	m_pLogger = new Logger();
};

void RenderStream::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
};

void RenderStream::setParams(QVector<QString> &params){
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

	m_pOutputFrame = new Frame(nWidth, nHeight);
	m_pRenderFrame = new Frame(nWidth, nHeight);
	m_pDrawObjectsCollection = new DrawObjectsCollection();
};

void RenderStream::setInputStream(InputStreamCommands *pInputStreamCommands){
	m_pInputStreamCommands = pInputStreamCommands;
};

Frame *RenderStream::outputFrame(){
	return m_pOutputFrame;
}

void RenderStream::run(){
	while(true){
		while(m_pInputStreamCommands->hasCommand()){
			ICommand *pCommand = m_pInputStreamCommands->command();
			if(pCommand->name() == "fix"){
				m_pOutputFrame->copy(m_pRenderFrame);
			}else{
				pCommand->run(m_pRenderFrame, m_pDrawObjectsCollection);
			}
			m_pLogger->debug("Executed " + pCommand->code());
		}
		QThread::msleep(200);
	};
};
