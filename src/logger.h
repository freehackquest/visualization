#ifndef LOGGER_H
#define LOGGER_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>

class Logger {
	public:
		Logger();
		Logger(QString filename);
		Logger(Logger *pLogger);
		void info(QString str);
		void debug(QString str);
		void error(QString str);
		void warn(QString str);
		void disable();
		void enable();
	private:
		void message(QString prefix, QString msg);
		bool m_bEnabled;
		QTextStream *m_pTextStream;
		QFile *m_pLogFile;
		QMutex m_Mutex;
		Logger *m_pLogger;
};

#endif // LOGGER_H
