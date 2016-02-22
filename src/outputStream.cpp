#include "outputStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QElapsedTimer>
#include <QPainter>
#include <QFontMetrics>
#include <QFontDatabase>

OutputStream::OutputStream(){
	m_pLogger = new Logger();
	generateFHQVisualizationPreview();
};

void OutputStream::generateFHQVisualizationPreview(){

	int nWidth = 1280;
	int nHeight = 720;
	QImage imgLogo(":/images/fhq2015.png");
	int nWidthLogo = imgLogo.width();
	int nHeightLogo = imgLogo.width();

	int id = QFontDatabase::addApplicationFont(":/fonts/hack.regular.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont font(family, 24);

	QFontMetrics fm(font);
	QString text = "visualization";
	int nTextWidth = fm.width(text);
	int nTextHeight = fm.height();
	int nFinishXText = nWidth/2 - nTextWidth/2;
	
	int nFinishXLogo = (nWidth-nWidthLogo)/2;
	int nY = (nHeight-nHeightLogo)/2;
	

	int nFrames = 3*2;
	int nDiff = (nWidth - nFinishXLogo)/nFrames;
	int nDiffText = (nFinishXText + nTextWidth)/nFrames;
	for(int fr = 0; fr < nFrames; fr++){
		QImage *pFrame = new QImage(QSize(nWidth,nHeight), QImage::Format_RGB32);
		pFrame->fill(QColor(0x303030));

		QPainter p(pFrame);
		p.setPen(QPen(QColor(0xFFC8C8C8)));
		p.setBrush(QBrush(QColor(0xFFC8C8C8)));
		int nX = (nWidth - nDiff*(fr+1));
		if (fr == nFrames-1)
			nX = nFinishXLogo;
		p.drawImage(QPoint(nX, nY), imgLogo);	
		p.setFont(font);
		p.setPen(QPen(QColor(0xFFC8C8C8)));
		
		int nXt = nDiffText*(fr+1) - nTextWidth;
		if (fr == nFrames-1){
			nXt = nFinishXText;
		}
		p.drawText(nXt, nY + 10 + nTextHeight + nHeightLogo, text);
		p.end();
		m_vFrames.push_back(pFrame);
	}
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
			for(int i = 0; i < nBytes; i++){
				std::cout << char(pBytes[i]);
			};
		}

		if(bRemove){
			delete pFrame;
		}
		// Correction output stream
		nExpected += 500; // 2 fps
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
