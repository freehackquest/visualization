#ifndef COMMAND_SKIP_H
#define COMMAND_SKIP_H
#include "../icommand.h"
#include <QString>
#include <QStringList>

class CommandSkip : public ICommand {
	public:
		CommandSkip();
		virtual bool isMultiLine();
		virtual ICommand *create();
		virtual QString name();
		virtual void setParams(QStringList list);
		virtual bool check();
		virtual bool check(QString &strResult);
		virtual QString code();
		virtual void appendCode(QString);
	private:
		QString m_strName;
		QStringList m_listParams;
};

#endif // COMMAND_SKIP_H
