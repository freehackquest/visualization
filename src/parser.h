#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QStringList>
#include <QVector>
#include "icommand.h"
#include "commandscollection.h"
#include "logger.h"

class Parser {
	public:
		Parser();
		void setLogger(Logger *pLogger);
		void parse(QString line);
		bool hasCommand();
		ICommand* command();
		void reset();
	private:
		void parseLine(QString line);
		bool m_bCommandCompleted;
		bool m_bMultiLineCommand;
		QString removeComment(QString);
		QStringList m_listCode;
		QString m_strCommandName;
		QStringList m_listSingleLineCommands;
		QVector<ICommand*> m_vCommands;
		ICommand* m_pTemporaryCommand;
		Logger *m_pLogger;
		CommandsCollection *m_pCommandsCollection;
};

#endif // PARSER_H
