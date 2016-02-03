#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QStringList>
#include <QVector>
#include "command.h"
#include "logger.h"

class Parser {
	public:
		Parser();
		void setLogger(Logger *pLogger);
		void parse(QString line);
		bool isCommandCompleted();
		bool hasCommand();
		Command command();
		void reset();
	private:
		void parseLine(QString line);
		bool m_bCommandCompleted;
		QString removeComment(QString);
		QStringList m_listCode;
		QString m_strCommandName;
		QStringList m_listSingleLineCommands;
		QVector<Command> m_vCommands;
		Logger *m_pLogger;
};

#endif // PARSER_H
