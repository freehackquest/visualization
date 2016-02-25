#ifndef COMMAND_PUSHFRAMES_H
#define COMMAND_PUSHFRAMES_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandPushFrames : public ICommand {
	public:
		CommandPushFrames();
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
		QString m_sCheck;
		bool m_bCheck;
};

#endif // COMMAND_PUSHFRAMES_H
