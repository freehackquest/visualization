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
#include <QImage>
#include <QColor>

#include <iostream>
#include <math.h>

#include "drawobjectscollection.h"
#include "frame.h"
#include "inputStreamCommands.h"
#include "outputStream.h"
#include "logger.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);

	QVector<QString> params;
	for(int i = 0; i < argc; i++){
		params.push_back(argv[i]);
	}

	{
		int n = params.indexOf("--convert-image");
		if(n > 0 && n+1 < params.size()){
			QString filename = params[n+1];
			QImage image(filename);
			int nCount = 0;
			int nWidth = image.width();
			int nHeight = image.height();
			int dX = (1280 - nWidth)/2;
			int dY = (720 - nHeight)/2;
			for(int x = 0; x < nWidth; x++){
				for(int y = 0; y < nHeight; y++){
					int n = image.pixel(x,y);
					int a = n >> 24 & 0xFF;
					if(a > 0){
						n = n & 0x00FFFFFF; 
						std::cout << "pixel " << x + dX << " " << y + dY << " " << QString::number(n,16).toStdString() << "\n";
						nCount++;
						if(nCount % 1000 == 0){
							std::cout << "fix\n";
						}
					}
				}
			}
			std::cout << "fix\n"; 
			return -1;
		}
	}

	Logger *pLogger = new Logger("visualization.log");
	pLogger->info("visualization started.");
	if(params.indexOf("--disablelog") >= 0)
		pLogger->disable();
	
	OutputStream *pOutputStream = new OutputStream();
	pOutputStream->setLogger(pLogger);
	InputStreamCommands *pInputStreamCommands = new InputStreamCommands();
	pInputStreamCommands->setLogger(pLogger);
	pInputStreamCommands->start(31001); // started server on 31001 port 

	pOutputStream->setInputStream(pInputStreamCommands);
	pOutputStream->setParams(params);
	pOutputStream->start();

	return app.exec();

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
