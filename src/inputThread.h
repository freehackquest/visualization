#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H
#include <QThread>
#include <QTextStream>
#include <QFile>
#include "parser.h"
#include "command.h"
#include "logger.h"
#include <QMutex>

class InputThread : public QThread {
		Q_OBJECT
		void run();	
	public:
		InputThread();
		void setLogger(Logger *pLogger);
		bool hasCommand();
		Command command();
		void pushCommand(Command command);
	private:
		bool m_bDebug;
		Parser *m_pParser;
		QTextStream *m_pLogFile;
		QFile *m_pFile;
		QVector<Command> m_vCommands;
		QMutex m_Mutex;
		Logger *m_pLogger;
};

#endif // INPUTTHREAD_H
