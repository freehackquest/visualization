#ifndef COMMAND_FIX_H
#define COMMAND_FIX_H
#include "../icommand.h"
#include <QString>
#include <QStringList>

class CommandFix : public ICommand {
	public:
		CommandFix();
		virtual bool isMultiLine();
		virtual ICommand *create();
		virtual QString name();
		virtual void setParams(QStringList list);
		virtual bool check();
		virtual bool check(QString &strResult);
		virtual QString code();
		virtual void appendCode(QString);
		virtual void run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection);
	private:
		QString m_strName;
		QString m_sCheck;
		bool m_bCheck;
};

#endif // COMMAND_FIX_H
