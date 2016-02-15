#ifndef HELPERS_LINE_H
#define HELPERS_LINE_H
#include "frame.h"
#include <QString>
#include <QStringList>

class HelpersLine {
	public:
		static int distance(int x1, int x2);
		static void draw(Frame *pFrame, int nX1, int nY1, int nX2, int nY2, int nWidth, int nColor);
};

#endif // HELPERS_LINE_H
