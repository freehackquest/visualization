#ifndef RENDERSTREAM_H
#define RENDERSTREAM_H
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

class RenderStream : public QThread{
		Q_OBJECT
	public:
		RenderStream();
		void setParams(QVector<QString> &params);
		void setLogger(Logger *pLogger);
		void setInputStream(InputStreamCommands *pInputStreamCommands);
		Frame *outputFrame();
		void run();
	private:
		Logger *m_pLogger;
		Frame *m_pOutputFrame;
		Frame *m_pRenderFrame;
		DrawObjectsCollection *m_pDrawObjectsCollection;
		InputStreamCommands *m_pInputStreamCommands;
};

#endif // RENDERSTREAM_H
