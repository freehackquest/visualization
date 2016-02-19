#ifndef HELPERS_TEXT_H
#define HELPERS_TEXT_H
#include "frame.h"
#include <QString>
#include <QStringList>

class HelpersText {
	public:
		static int width(QString nFontName, int nFontSize, QString sText);
		static void draw(Frame *pFrame, int nX1, int nY1, int nColor, QString nFontName, int nFontSize, QString sText);
};

#endif // HELPERS_TEXT_H
