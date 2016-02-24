#ifndef COMMAND_TABLE_H
#define COMMAND_TABLE_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandTable : public ICommand {
	public:
		CommandTable();
		virtual bool isMultiLine();
		virtual ICommand *create();
		virtual QString name();
		virtual void setParams(QStringList list);
		virtual bool check();
		virtual bool check(QString &strResult);
		virtual QString code();
		virtual void appendCode(QString);
		virtual void run(ICore *pCore);
	private:
		
		QString m_strName;
		QStringList m_listParams;
		QStringList m_listCode;
};

#endif // COMMAND_TABLE_H
