#include "helpersText.h"
#include <iostream>
#include <QString>
#include <QMap>

int HelpersText::width(QString nFontName, int nFontSize, QString sText){
	// TODO redesign
	return nFontSize*sText.length();
}

void HelpersText::draw(Frame *pFrame, int nX, int nY, int nColor, QString sFontName, int nFontSize, QString sText){
	
	// sFontName
	
	for(int i = 0; i < sText.length(); i++){
		QChar ch = sText.at(i);
		if(ch == '0'){
			for(int x = nX+2; x < nX + nFontSize-2; x++){
				pFrame->setPixel(x,nY,nColor);
				pFrame->setPixel(x,nY+1,nColor);
				pFrame->setPixel(x,nY+nFontSize,nColor);
				pFrame->setPixel(x,nY+nFontSize-1,nColor);
			}
			for(int y = nY; y < nY+nFontSize; y++){
				pFrame->setPixel(nX+2,y,nColor);
				pFrame->setPixel(nX+3,y,nColor);
				pFrame->setPixel(nX + nFontSize-2,y,nColor);
				pFrame->setPixel(nX + nFontSize-3,y,nColor);
			}
		}else{
			pFrame->setPixel(int(nX + nFontSize*i),int(nY),nColor);
		}
	}
};
