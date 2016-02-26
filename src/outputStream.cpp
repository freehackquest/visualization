#include "outputStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QElapsedTimer>
#include <cstring>
#include <QMutexLocker>
#include "commands/fhqvisualization.h"

OutputStream::OutputStream(ICore *pCore){
	m_pLogger = pCore->logger();
	m_pCore = pCore;
	m_pLogger->info("OutputStream created");
};

void OutputStream::addFrame(QImage *m_pFrame){
	QMutexLocker lock(&m_mtxFrames);
	m_vFrames.push_back(m_pFrame);
};

void OutputStream::run(){
	m_pLogger->info("OutputStream started");
	{
		ICommand *pCommand = new CommandFHQVisualization();
		pCommand->run(m_pCore);
		m_pLogger->info("OutputStream Generated FHQVisualization Preview");
		delete pCommand;
	}

	QElapsedTimer timer;
	timer.start();
	qint64 nExpected = 0;
	int nDiff_ms = 1000/m_pCore->framerate();
	const int frameBufSize = m_pCore->width()*m_pCore->height()*4;
	char frameBuf[frameBufSize];
	std::memset(frameBuf,0,frameBufSize);
	while(true){
		QImage *pFrame = NULL;
		if(m_vFrames.size()>0){
			// m_pLogger->info("OutputStream has frame");
			QMutexLocker lock(&m_mtxFrames);
			pFrame = m_vFrames.front();
			m_vFrames.pop_front();
			std::memcpy(frameBuf, pFrame->bits(), pFrame->byteCount());
			delete pFrame;
		}

		fwrite(frameBuf, frameBufSize, 1, stdout);

		// Correction output stream
		nExpected += nDiff_ms;
		qint64 nElapsed = timer.elapsed();
		qint64 nDiff = nExpected - nElapsed;
		if(nDiff >= 0){
			QThread::msleep(nDiff);
			// m_pLogger->debug("Expected: " + QString::number(nExpected) + "; Elapsed: " + QString::number(nElapsed));
		}else{
			if(nElapsed > 5000){
				timer.restart();
				nElapsed = 0;
			}
			m_pLogger->error("Elapsed more then Expected: " + QString::number(-1*nDiff));
			continue;
		}
	};
};
