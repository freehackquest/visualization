#ifndef LOGGER_H
#define LOGGER_H
#include "interfaces/ilogger.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>

class Logger : public ILogger{
	public:
		Logger();
		Logger(QString filename);
		Logger(Logger *pLogger);
		virtual void info(QString str);
		virtual void debug(QString str);
		virtual void error(QString str);
		virtual void warn(QString str);
		virtual void disable();
		virtual void enable();
	private:
		void message(QString prefix, QString msg);
		bool m_bEnabled;
		QTextStream *m_pTextStream;
		QFile *m_pLogFile;
		QMutex m_Mutex;
		Logger *m_pLogger;
};

#endif // LOGGER_H
