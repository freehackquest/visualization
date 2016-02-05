#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H
#include <QThread>
#include <QTextStream>
#include <QFile>
#include "parser.h"
#include "icommand.h"
#include "logger.h"
#include <QMutex>

class InputThread : public QThread {
		Q_OBJECT
		void run();	
	public:
		InputThread();
		void setLogger(Logger *pLogger);
		bool hasCommand();
		ICommand *command();
		void pushCommand(ICommand *pCommand);
	private:
		bool m_bDebug;
		Parser *m_pParser;
		QTextStream *m_pLogFile;
		QFile *m_pFile;
		QVector<ICommand *> m_vCommands;
		QMutex m_Mutex;
		Logger *m_pLogger;
};

#endif // INPUTTHREAD_H
