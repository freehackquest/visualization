#include "helpersLine.h"
#include <iostream>
#include <QString>

int HelpersLine::distance(int x1, int x2){
	if(x2 > x1)
		return x2-x1;
	return x1-x2;
}

void HelpersLine::draw(Frame *pFrame, int nX1, int nY1, int nX2, int nY2, int nWidth, int nColor){
	int nDistanceX = HelpersLine::distance(nX2,nX1);
	int nDistanceY = HelpersLine::distance(nY2,nY1);
	double nDX = 1;
	double nDY = 1;
	int nLength = 0;

	if(nDistanceX > nDistanceY){
		nDY = double(nDistanceY)/double(nDistanceX);
		nLength = nDistanceX;
	}else{
		nDX = double(nDistanceX)/double(nDistanceY);
		nLength = nDistanceY;
	}

	nDX = nX2 > nX1 ? nDX : -1*nDX;
	nDY = nY2 > nY1 ? nDY : -1*nDY;
		
	double x = nX1;
	double y = nY1;
	for(int i = 0; i < nLength; i++){
		x=x+nDX;
		y=y+nDY;
		pFrame->setPixel(int(x),int(y),nColor);
	}
};

