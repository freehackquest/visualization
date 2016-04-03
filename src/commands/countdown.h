#ifndef COMMAND_COUNTDOWN_H
#define COMMAND_COUNTDOWN_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandCountDown : public ICommand {
	public:
		CommandCountDown();
		virtual ~CommandCountDown();
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
		int m_nSeconds;
		QString m_sFinishText;
		bool m_bCheck;
		QString m_sCheck;
};

#endif // COMMAND_COUNTDOWN_H
