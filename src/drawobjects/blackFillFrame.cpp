
#include "blackFillFrame.h"

QString DrawObject_blackFillFrame::name(){
	return "blackFillFrame";
};

void DrawObject_blackFillFrame::draw(Frame *pFrame, int, int){
	for(int y = 0; y < pFrame->height(); y++){
		for(int x = 0; x < pFrame->width(); x++){
			pFrame->setPixel(x,y,0x00000000);
		}
	}
};
