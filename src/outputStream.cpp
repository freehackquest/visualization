
#include "outputStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QElapsedTimer>
#include <QPainter>

OutputStream::OutputStream(){
	m_pLogger = new Logger();

	// Create first frame (FHQ Visualization)
	QImage *pFirstFrame = new QImage(QSize(1280,720), QImage::Format_RGB32);
	pFirstFrame->fill(QColor(0x303030));
	QPainter p(pFirstFrame);
	p.setPen(QPen(QColor(0x303030)));
	// p.setBrush(QBrush(QColor(0x303030), Qt::NoBrush));
	// p.setBrush(QBrush(QColor(0xFF303030)));
	p.setBrush(QBrush(QColor(48,48,48)));
	p.drawRect(QRect(0,0,5,5));

	/*QImage imgLogo(":/images/fhq2015.jpg");
	QPoint destPos = QPoint((pFirstFrame->width()-imgLogo.width())/2, (pFirstFrame->height()-imgLogo.height())/2);
	p.drawImage(destPos, imgLogo);*/
	// pFirstFrame->fill(0xFF303030);
	// pFirstFrame->fill(0xFFFFFFFF);
	// pFirstFrame->fill(0xFF000000);
	p.end();
	m_vFrames.push_back(pFirstFrame);
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
		QImage *pFrame = NULL;
		int nSize = m_vFrames.size();
		bool bRemove = false;
		if(nSize>1){
			pFrame = m_vFrames.front();
			m_vFrames.pop_front();
			bRemove = true;
		}else if(nSize == 1){
			pFrame = m_vFrames.front();
		}

		if(pFrame != NULL){
			uchar *pBytes = pFrame->bits();
			int nBytes = pFrame->byteCount();
			for(int i = 0; i < nBytes/4; i++){
				int nPos = i*4;
				std::cout << char(pBytes[nPos+1]);
				std::cout << char(pBytes[nPos+2]);
				std::cout << char(pBytes[nPos+3]);
			};
		}
		// Correction output stream
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
