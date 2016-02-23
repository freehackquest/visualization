#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H
#include <QTextStream>
#include <QFile>
#include "parser.h"
#include "icommand.h"
#include "frame.h"
#include "inputStreamCommands.h"
#include "logger.h"
#include <QWidget>
#include <QMutex>
#include <QtNetwork>
#include <QThread>
#include <QImage>
#include <QMutex>

class OutputStream : public QThread{
		Q_OBJECT
	public:
		OutputStream();
		void setLogger(Logger *pLogger);
		void setFrame(Frame *m_pOuputFrame);
		void addFrame(QImage *m_pFrame);
		void run();
		int width();
		int height();
		int framerate();
	private:
		void generateFHQVisualizationPreview();
		Logger *m_pLogger;
		Frame *m_pOutputFrame;
		QVector<QImage *> m_vFrames;
		QMutex m_mtxFrames;
};

#endif // OUTPUTSTREAM_H
