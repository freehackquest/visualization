#include "outputStream.h"
#include <iostream>
#include <QString>
#include <QMutexLocker>
#include <QElapsedTimer>
#include <QPainter>
#include <QFontMetrics>
#include <QFontDatabase>
#include <cstring>
#include <QMutexLocker>

OutputStream::OutputStream(){
	m_pLogger = new Logger();
	generateFHQVisualizationPreview();
};

int OutputStream::width(){
	return 1280;
};

int OutputStream::height(){
	return 720;
};

int OutputStream::framerate(){
	return 10;
};

void OutputStream::generateFHQVisualizationPreview(){

	int nWidth = width();
	int nHeight = height();
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
	

	int nFrames = 3*framerate();
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
		addFrame(pFrame);
	}
};

void OutputStream::setLogger(Logger *pLogger){
	m_pLogger = pLogger;
};

void OutputStream::setFrame(Frame *pFrame){
	m_pOutputFrame = pFrame;
};

void OutputStream::addFrame(QImage *m_pFrame){
	QMutexLocker lock(&m_mtxFrames);
	m_vFrames.push_back(m_pFrame);
};

void OutputStream::run(){
	QElapsedTimer timer;
	timer.start();
	qint64 nExpected = 0;
	int nDiff_ms = 1000/framerate();
	const int frameBufSize = width()*height()*4+1;
	char frameBuf[frameBufSize];
	std::memset(frameBuf,0,frameBufSize);
	while(true){

		QImage *pFrame = NULL;
		if(m_vFrames.size()>0){
			QMutexLocker lock(&m_mtxFrames);
			pFrame = m_vFrames.front();
			m_vFrames.pop_front();
			std::memcpy(frameBuf, pFrame->bits(), pFrame->byteCount());
			delete pFrame;
		}

		std::cout << frameBuf;

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
