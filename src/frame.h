#ifndef FRAME_H
#define FRAME_H

#include <QMutex>

class Frame {
		int **m_pFrame;
		int m_nWidth;
		int m_nHeight;
		QMutex m_mtxCopy;
	public:
		Frame(int w, int h);
		int width();
		int height();
		void setPixel(int x, int y, int nColor);
		int ** unsafe();
		QMutex &mutex();
		void copy(Frame *pFrame);
		void outputToStd();
};

#endif // FRAME_H
