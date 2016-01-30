
#include "h1_G_lower.h"

QString DrawObject_h1_G_lower::name(){
	return "h1_G_lower";
};

void DrawObject_h1_G_lower::draw(Frame *pFrame, int nX, int nY){
	
	for(int y = 100; y < 200; y++){
		for(int x = 0; x < 10; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}

	for(int y = 100; y < 300; y++){
		for(int x = 90; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
	
	for(int y = 100; y < 110; y++){
		for(int x = 0; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
	
	for(int y = 190; y < 200; y++){
		for(int x = 0; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
	
	for(int y = 290; y < 300; y++){
		for(int x = 0; x < 100; x++){
			pFrame->setPixel(nX+x,nY+y,0x00FFFFFF);
		}
	}
};
