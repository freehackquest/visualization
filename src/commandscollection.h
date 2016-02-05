#ifndef COMMANDS_COLLECTION_H
#define COMMANDS_COLLECTION_H
#include "icommand.h"
#include <QString>
#include <QMap>

class CommandsCollection {
	public:
		CommandsCollection();
		bool contains(QString name);
		ICommand *create(QString name);
		bool isMultiLine(QString name);
	private:
		void registr(ICommand*);
		QMap<QString, ICommand*> m_mapCommands;
		ICommand* m_pCurCommand;
};

#endif // COMMANDS_COLLECTION_H
