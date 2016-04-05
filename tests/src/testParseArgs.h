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
    void testParseArgs1();
    void testParseArgs2();
    void testParseArgs3();
    void testParseArgs4();
    void testParseArgs5();
    void testParseArgs6();
    void testParseArgs7();
    void testParseArgs8();
    
};

#endif // TEST_PARSEARGS_H
