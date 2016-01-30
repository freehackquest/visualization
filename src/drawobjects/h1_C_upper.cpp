
#include "h1_C_upper.h"

QString DrawObject_h1_C_upper::name(){
	return "h1_C_upper";
};

void DrawObject_h1_C_upper::draw(Frame *pFrame, int nX, int nY){
	
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
	
	for(int y = 190; y < 200; y++){
		for(int x = 0; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
};
