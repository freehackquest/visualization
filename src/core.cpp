#include "core.h"

Core::Core(ILogger *pLogger){
	m_pLogger = pLogger;
	m_nWidth = 1280;
	m_nHeight = 720;
	m_nFramerate = 10;
	m_nPort = 31001;
	
	// init input streams
	m_pInputStreamCommands = new InputStreamCommands(this);
	m_pRenderStream = new RenderStream(this);
	m_pOutputStream = new OutputStream(this);

	m_pRenderStream->setInputStream(m_pInputStreamCommands);
	m_pRenderStream->setOutputStream(m_pOutputStream);

};

QImage * Core::createFrame(){
	QMutexLocker lock(&m_mtxFrames);
	QImage *pFrame = new QImage(QSize(width(),height()), QImage::Format_RGB32);
	pFrame->fill(QColor(0x303030));
	m_vFrames.push_back(pFrame);
	return pFrame;
};

QImage * Core::lastFrame(){
	QMutexLocker lock(&m_mtxFrames);
	if(m_vFrames.size() == 0){
		QImage *pFrame = new QImage(QSize(width(),height()), QImage::Format_RGB32);
		pFrame->fill(QColor(0x303030));
		m_vFrames.push_back(pFrame);
	}
	return m_vFrames.last();
};

void Core::fix(){
	QMutexLocker lock(&m_mtxFrames);
	for(int i = 0; i < m_vFrames.size(); i++){
		m_pOutputStream->addFrame(m_vFrames[i]);
	}
	m_vFrames.clear();
};

ILogger *Core::logger(){
	return m_pLogger;
};

int Core::port(){
	return m_nPort;
};

int Core::width(){
	return m_nWidth;
};

int Core::height(){
	return m_nHeight;
}

int Core::framerate(){
	return m_nFramerate;
};

void Core::start(){
	m_pInputStreamCommands->start(port());
	m_pOutputStream->start();
	m_pRenderStream->start();
}
