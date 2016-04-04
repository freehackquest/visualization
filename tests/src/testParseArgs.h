#ifndef TEST_PARSEARGS_H
#define TEST_PARSEARGS_H

#include <QTest>

#include <QObject>

class TestParseArgs : public QObject
{
    Q_OBJECT
public:
    explicit TestParseArgs(QObject *parent = 0);

private slots:
    void testParse();
    
};

#endif // TEST_PARSEARGS_H
