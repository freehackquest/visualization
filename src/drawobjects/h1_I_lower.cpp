
#include "h1_I_lower.h"

QString DrawObject_h1_I_lower::name(){
	return "h1_I_lower";
};

void DrawObject_h1_I_lower::draw(Frame *pFrame, int nX, int nY){


	for(int y = 100; y < 200; y++){
		for(int x = 45; x < 55; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}

	for(int y = 80; y < 90; y++){
		for(int x = 45; x < 55; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
};
