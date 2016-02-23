
#include "renderStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>

RenderStream::RenderStream(){
	m_pLogger = new Logger();
	m_pInputStreamCommands = NULL;
	m_pOutputStream = NULL;
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
};

void RenderStream::setInputStream(InputStreamCommands *pInputStreamCommands){
	m_pInputStreamCommands = pInputStreamCommands;
};

void RenderStream::setOutputStream(OutputStream *pOutputStream){
	m_pOutputStream = pOutputStream;
};

Frame *RenderStream::outputFrame(){
	return m_pOutputFrame;
}

void RenderStream::run(){
	while(true){
		QVector<QImage*> vFrames;
		while(m_pInputStreamCommands->hasCommand()){
			ICommand *pCommand = m_pInputStreamCommands->command();
			if(pCommand->name() == "fix"){
				// TODO add to output stream
				for(int i = 0; i < vFrames.size(); i++){
					m_pOutputStream->addFrame(vFrames[i]);
				}
				vFrames.clear();
			}else{
				pCommand->run(vFrames);
			}
			m_pLogger->debug("Executed " + pCommand->code());
		}
		QThread::msleep(1000/m_pOutputStream->framerate());
	};
};
