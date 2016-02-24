#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H
#include <QTextStream>
#include <QFile>
#include "inputStreamCommands.h"
#include "interfaces/ilogger.h"
#include "interfaces/icore.h"
#include <QWidget>
#include <QMutex>
#include <QtNetwork>
#include <QThread>
#include <QImage>
#include <QMutex>

class OutputStream : public QThread{
		Q_OBJECT
	public:
		OutputStream(ICore *pCore);
		void addFrame(QImage *m_pFrame);
		void run();
	private:
		void generateFHQVisualizationPreview();
		ILogger *m_pLogger;
		ICore *m_pCore;
		QVector<QImage *> m_vFrames;
		QMutex m_mtxFrames;
};

#endif // OUTPUTSTREAM_H
