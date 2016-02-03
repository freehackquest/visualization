#ifndef LOGGER_H
#define LOGGER_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>

class Logger {
	public:
		Logger(QString filename);
		void info(QString str);
		void debug(QString str);
		void error(QString str);
		void disable();
		void enable();
	private:
		void message(QString prefix, QString msg);
		bool m_bEnabled;
		QTextStream *m_pTextStream;
		QMutex m_Mutex;
};

#endif // LOGGER_H
