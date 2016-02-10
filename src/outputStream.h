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

class OutputStream : public QThread{
		Q_OBJECT
	public:
		OutputStream();
		void setParams(QVector<QString> &params);
		void setLogger(Logger *pLogger);
		void setInputStream(InputStreamCommands *pInputStreamCommands);
		void run();
	private:
		Logger *m_pLogger;
		Frame *m_pFrame;
		DrawObjectsCollection *m_pDrawObjectsCollection;
		InputStreamCommands *m_pInputStreamCommands;
};

#endif // OUTPUTSTREAM_H
