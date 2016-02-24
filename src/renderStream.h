#ifndef RENDERSTREAM_H
#define RENDERSTREAM_H
#include <QTextStream>
#include <QFile>
#include "parser.h"
#include "inputStreamCommands.h"
#include "outputStream.h"
#include "logger.h"
#include "interfaces/icore.h"
#include <QWidget>
#include <QMutex>
#include <QtNetwork>
#include <QThread>

class RenderStream : public QThread{
		Q_OBJECT
	public:
		RenderStream(ICore *pCore);
		void setInputStream(InputStreamCommands *pInputStreamCommands);
		void setOutputStream(OutputStream *pOutputStream);
		void run();
	private:
		ILogger *m_pLogger;
		ICore *m_pCore;
		InputStreamCommands *m_pInputStreamCommands;
		OutputStream *m_pOutputStream;
};

#endif // RENDERSTREAM_H
