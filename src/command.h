#ifndef COMMAND_H
#define COMMAND_H
#include <QString>
#include <QStringList>

class Command {
	public:
		Command();
		void setName(QString name);
		void setParams(QStringList list);
		bool check();
		bool check(QString &strResult);
		QString toString();
	private:
		QString m_strName;
		QStringList m_listParams;
};

#endif // COMMAND_H
