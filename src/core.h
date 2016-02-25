#ifndef CORE_H
#define CORE_H

#include <QVector>
#include <QImage>

#include "interfaces/icore.h"
#include "inputStreamCommands.h"
#include "renderStream.h"
#include "outputStream.h"
#include "logger.h"

class Core : public ICore {
	public:
		Core(ILogger *pLogger);
		virtual ILogger *logger();
		virtual int width();
		virtual int height();
		virtual int port();
		virtual int framerate();
		virtual void start();
		virtual QImage * createFrame();
		virtual QImage * lastFrame();
		virtual void pushFrames();

	private:
		int m_nWidth;
		int m_nPort;
		int m_nHeight;
		int m_nFramerate;
		ILogger *m_pLogger;
		InputStreamCommands *m_pInputStreamCommands;
		RenderStream *m_pRenderStream;
		OutputStream *m_pOutputStream;
		QMutex m_mtxFrames;
		QVector<QImage*> m_vFrames;
};

#endif // CORE_H
