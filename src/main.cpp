#include <QApplication>
#include <QString>
#include <QMap>
#include <QDir>
#include <QImage>
#include <QTime>
#include <QFont>
#include <QList>
#include <QPaintDevice>
#include <QVector>

#include <iostream>
#include <math.h>

#include "drawobjectscollection.h"
#include "frame.h"
#include "inputThread.h"
#include "logger.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);

	QVector<QString> params;
	for(int i = 0; i < argc; i++){
		params.push_back(argv[i]);
	}
	Logger *pLogger = new Logger("visualization.log");
	pLogger->info("visualization started.");
	if(params.indexOf("--disablelog") >= 0)
		pLogger->disable();
	
	InputThread *pInputThread = new InputThread();
	pInputThread->setLogger(pLogger);
	pInputThread->start();

	int nFrameRate = 5;
	int nSeconds = -1;
	int nWidth = 1280;
	int nHeight = 720;

	{
		int n = params.indexOf("--framerate");
		if(n > 0 && n+1 < params.size()){
			nFrameRate = params[n+1].toInt();
		}
	}

	{
		int n = params.indexOf("--time");
		if(n > 0 && n+1 < params.size()){
			nSeconds = params[n+1].toInt();
		}
	}

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

	Frame *pFrame = new Frame(nWidth, nHeight);
	DrawObjectsCollection *pDrawObjectsCollection = new DrawObjectsCollection();

	while(true){
		while(pInputThread->hasCommand()){
			ICommand *pCommand = pInputThread->command();
			pCommand->run(pFrame, pDrawObjectsCollection);
		}
		QThread::msleep(100);
		pFrame->outputToStd();
	};
	/*
	// Create seed for the random
	// That is needed only once on application startup
	QTime time = QTime::currentTime();
	qsrand((uint)time.msec());

	int s = 0;
	while(s < nSeconds || nSeconds == -1){
		s++;
		for(int f = 0; f < nFrameRate; f++){
			int y = (720 - 20)/2 - 200/2;
			int x = (1280 - 20)/2 - (7*110)/2;
			int dx = qrand()%200 - 100;
			int dy = qrand()%200 - 100;
			// int dx = 0;
			pDrawObjectsCollection->draw("blackFillFrame", pFrame, 0, 0);
			pDrawObjectsCollection->draw("whiteBorderFrame", pFrame, 0, 0);
			int L = (qrand() % 8);
			switch (L) {
				case 0:
					pDrawObjectsCollection->draw("h1_C_upper", pFrame, x + 0*110 + dx, y + dy);
					break;
				case 1:
					pDrawObjectsCollection->draw("h1_T_upper", pFrame, x + 1*110 + dx, y + dy);
					break;
				case 2:
					pDrawObjectsCollection->draw("h1_F_upper", pFrame, x + 2*110 + dx, y + dy);
					break;
				case 3:
					pDrawObjectsCollection->draw("h1_I_lower", pFrame, x + 3*110 + dx, y + dy);
					break;
				case 4:
					pDrawObjectsCollection->draw("h1_G_lower", pFrame, x + 4*110 + dx, y + dy);
					break;
				case 5:
					pDrawObjectsCollection->draw("h1_H_lower", pFrame, x + 5*110 + dx, y + dy);
					break;
				case 6:
					pDrawObjectsCollection->draw("h1_T_lower", pFrame, x + 6*110 + dx, y + dy);
					break;
				case 7:
					pDrawObjectsCollection->draw("h1_C_upper", pFrame, x + 0*110, y);
					pDrawObjectsCollection->draw("h1_T_upper", pFrame, x + 1*110, y);
					pDrawObjectsCollection->draw("h1_F_upper", pFrame, x + 2*110, y);
					pDrawObjectsCollection->draw("h1_I_lower", pFrame, x + 3*110, y);
					pDrawObjectsCollection->draw("h1_G_lower", pFrame, x + 4*110, y);
					pDrawObjectsCollection->draw("h1_H_lower", pFrame, x + 5*110, y);
					pDrawObjectsCollection->draw("h1_T_lower", pFrame, x + 6*110, y);
					break;
			}
			pFrame->outputToStd();
		}
	}*/
	return 0;
}
