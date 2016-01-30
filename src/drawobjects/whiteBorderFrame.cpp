
#include "whiteBorderFrame.h"

QString DrawObject_whiteBorderFrame::name(){
	return "whiteBorderFrame";
};

void DrawObject_whiteBorderFrame::draw(Frame *pFrame, int, int){

	int w = pFrame->width();
	int h = pFrame->height();

	for(int y = 0; y < 10; y++){
		for(int x = 0; x < w; x++){
			pFrame->setPixel(x,y,0x00FFFFFF);
		}
	}
	
	for(int y = h-10; y < h; y++){
		for(int x = 0; x < w; x++){
			pFrame->setPixel(x,y,0x00FFFFFF);
		}
	}
	
	for(int y = 0; y < h; y++){
		for(int x = 0; x < 10; x++){
			pFrame->setPixel(x,y,0x00FFFFFF);
		}
	}
	
	for(int y = 0; y < h; y++){
		for(int x = w-10; x < w; x++){
			pFrame->setPixel(x,y,0x00FFFFFF);
		}
	}
};
