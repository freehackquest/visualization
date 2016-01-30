
#include "frame.h"
#include <iostream>

Frame::Frame(int w, int h){
	m_nWidth = w;
	m_nHeight = h;
	
	m_pFrame = new int*[m_nWidth];
	for(int x = 0; x < m_nWidth; x++){
		m_pFrame[x] = new int[m_nHeight];
	}
};

int Frame::width(){
	return m_nWidth;
}

int Frame::height(){
	return m_nHeight;
}

void Frame::setPixel(int x, int y, int nColor){
	if(x >= 0 && x < m_nWidth && y >= 0 && y < m_nHeight){
		m_pFrame[x][y] = nColor;
	}
}

void Frame::outputToStd(){
	for(int y = 0; y < m_nHeight; y++){
		for(int x = 0; x < m_nWidth; x++){
			int d = m_pFrame[x][y];
			std::cout << char((d >> 16)  & 0x000000FF);
			std::cout << char((d >> 8)  & 0x000000FF);
			std::cout << char((d >> 0)  & 0x000000FF);
		}
	}
}


