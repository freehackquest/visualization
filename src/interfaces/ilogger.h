#ifndef ILOGGER_H
#define ILOGGER_H
#include <QString>

class ILogger {
	public:
		virtual void info(QString str) = 0;
		virtual void debug(QString str) = 0;
		virtual void error(QString str) = 0;
		virtual void warn(QString str) = 0;
		virtual void disable() = 0;
		virtual void enable() = 0;
};

#endif // ILOGGER_H
