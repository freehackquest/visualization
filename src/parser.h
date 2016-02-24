#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QStringList>
#include <QVector>
#include "interfaces/icommand.h"
#include "interfaces/ilogger.h"
#include "commandscollection.h"

class Parser {
	public:
		Parser(ICore *pCore);
		void setLogger(ILogger *pLogger);
		void parse(QString line);
		bool hasCommand();
		ICommand* command();
	private:
		void parseLine(QString line);
		ICore *m_pCore;
		bool m_bCommandCompleted;
		bool m_bMultiLineCommand;
		QString removeComment(QString);
		QStringList m_listCode;
		QVector<ICommand*> m_vCommands;
		ICommand* m_pTemporaryCommand;
		ILogger *m_pLogger;
		CommandsCollection *m_pCommandsCollection;
};

#endif // PARSER_H
