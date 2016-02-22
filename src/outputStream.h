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

class OutputStream : public QThread{
		Q_OBJECT
	public:
		OutputStream();
		void setLogger(Logger *pLogger);
		void setFrame(Frame *m_pOuputFrame);
		void run();
	private:
		Logger *m_pLogger;
		Frame *m_pOutputFrame;
		QVector<QImage *> m_vFrames;
};

#endif // OUTPUTSTREAM_H
