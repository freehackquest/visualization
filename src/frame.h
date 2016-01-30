#ifndef FRAME_H
#define FRAME_H

class Frame {
		int **m_pFrame;
		int m_nWidth;
		int m_nHeight;
	public:
		Frame(int w, int h);
		int width();
		int height();
		void setPixel(int x, int y, int nColor);
		void outputToStd();
};

#endif // FRAME_H
