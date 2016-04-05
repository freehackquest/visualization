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
    void testParseArgs01();
    void testParseArgs02();
    void testParseArgs03();
    void testParseArgs04();
    void testParseArgs05();
    void testParseArgs06();
    void testParseArgs07();
    void testParseArgs08();
    void testParseArgs09();
    void testParseArgs10();
    void testParseArgs11();
};

#endif // TEST_PARSEARGS_H
