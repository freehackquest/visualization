#ifndef COMMAND_BACKGROUND_H
#define COMMAND_BACKGROUND_H
#include "../icommand.h"
#include <QString>
#include <QStringList>

class CommandBackground : public ICommand {
	public:
		CommandBackground();
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
		QStringList m_listParams;
};

#endif // COMMAND_BACKGROUND_H
