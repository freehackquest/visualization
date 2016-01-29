#include <QApplication>
#include <QString>
#include <QMap>
#include <QDir>
#include <QImage>
#include <QTime>
#include <QPainter>
#include <QFont>
#include <QList>
#include <QPaintDevice>

#include <iostream>
#include <math.h>

// #include "seakgObjects2D.h"

int g_nWidth = 1280;
int g_nHeight = 720;
int g_nFrameRate = 25;
int g_nSeconds = 5;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	// Create seed for the random
	// That is needed only once on application startup
	QTime time = QTime::currentTime();
	qsrand((uint)time.msec());

	//int nBytes = g_nWidth*g_nHeight;
	// int nMiddle = g_nWidth/2;

	int **pFrame = new int*[g_nWidth];
	for(int x = 0; x < g_nWidth; x++){
		pFrame[x] = new int[g_nHeight];
	}

	// 1382400 == 1920*720 == 1280*1080
	// 1280*720 = 921600
	// 460800 == 460800
	// One frame is W*H*1.5;

	for(int x = 0; x < g_nWidth; x++){
		for(int y = 0; y < g_nHeight; y++){
			pFrame[x][y] = 0x00000000;
			if(x >= 0 && x < 10){
				pFrame[x][y] = 0x00FFFFFF;
			}

			if(x > g_nWidth - 10 && x < g_nWidth){
				pFrame[x][y] = 0x00FF0000;
			}

			if(y >= 0 && y < 10){
				pFrame[x][y] = 0x000000FF;
			}

			if(y > g_nHeight - 10 && y < g_nHeight){
				pFrame[x][y] = 0x0000FF00;
			}
		}
	}


	// output
	for(int s = 0; s < g_nSeconds; s++){
		for(int f = 0; f < g_nFrameRate; f++){
	for(int i = 0; i < 720; i++)
		std::cout << char(0x00) << char(0x00) << char(0x00);
			for(int x = 0; x < g_nWidth; x++){
				for(int y = 0; y < g_nHeight; y++){
					int d = pFrame[x][y];
					std::cout << char((d >> 16)  & 0x000000FF);
					std::cout << char((d >> 8)  & 0x000000FF);
					std::cout << char((d >> 0)  & 0x000000FF);
				}
			}
		}
	}
	return 0;
}
