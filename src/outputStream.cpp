
#include "outputStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QElapsedTimer>

OutputStream::OutputStream(){
	m_pLogger = new Logger();
};

void OutputStream::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
};

void OutputStream::setFrame(Frame *pFrame){
	m_pOutputFrame = pFrame;
};

void OutputStream::run(){
	QElapsedTimer timer;
	timer.start();
	qint64 nExpected = 0;
	while(true){
		m_pOutputFrame->outputToStd();
		nExpected += 200; // 5 fps
		qint64 nElapsed = timer.elapsed();
		qint64 nDiff = nExpected - nElapsed;

		if(nDiff >= 0){
			QThread::msleep(nDiff);
		}else{
			m_pLogger->error("Elapsed more then Expected: " + QString::number(-1*nDiff));
			continue;
		}
	};
};
