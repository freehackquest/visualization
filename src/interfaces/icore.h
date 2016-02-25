#ifndef ICORE_H
#define ICORE_H
#include <QString>
#include <QStringList>
#include <QVector>
#include <QImage>
#include "ilogger.h"

class ICore {
	public:
		virtual ILogger *logger() = 0;
		virtual int width() = 0;
		virtual int height() = 0;
		virtual int port() = 0;
		virtual int framerate() = 0;
		virtual void start() = 0;
		// for work with frames
		virtual QImage * createFrame() = 0;
		virtual QImage * lastFrame() = 0;
		virtual void pushFrames() = 0;
};

#endif // ICORE_H
