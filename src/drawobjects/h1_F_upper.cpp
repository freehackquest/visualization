
#include "h1_F_upper.h"

QString DrawObject_h1_F_upper::name(){
	return "h1_F_upper";
};

void DrawObject_h1_F_upper::draw(Frame *pFrame, int nX, int nY){

	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}

	for(int y = 0; y < 200; y++){
		for(int x = 0; x < 10; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}

	for(int y = 95; y < 105; y++){
		for(int x = 0; x < 50; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
};
