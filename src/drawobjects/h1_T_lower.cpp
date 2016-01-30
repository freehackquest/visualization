
#include "h1_T_lower.h"

QString DrawObject_h1_T_lower::name(){
	return "h1_T_lower";
};

void DrawObject_h1_T_lower::draw(Frame *pFrame, int nX, int nY){


	for(int y = 0; y < 200; y++){
		for(int x = 45; x < 55; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}

	for(int y = 95; y < 105; y++){
		for(int x = 0; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
	
	for(int y = 190; y < 200; y++){
		for(int x = 45; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
};
