#include <iostream>
#include "testParseArgs.h"
#include "../src/helpers/parseArgs.h"
#include <QStringList>
TestParseArgs::TestParseArgs(QObject *parent) :
    QObject(parent)
{
}

void TestParseArgs::testParseArgs1()
{
	QStringList list = HelpersParseArgs::parse("test 5 123abc abc456 13.87 good");
	QVERIFY(list.size() == 6);
	QVERIFY(list[0] == "test");
	QVERIFY(list[1] == "5");
	QVERIFY(list[2] == "123abc");
	QVERIFY(list[3] == "abc456");
	QVERIFY(list[4] == "13.87");
	QVERIFY(list[5] == "good");
    /*Smart a;
    QCOMPARE(a.max(1,   0), 1);
    QCOMPARE(a.max(-1,  1), 1);
    QCOMPARE(a.max(4,   8), 8);
    QCOMPARE(a.max(0,   0), 0);
    QCOMPARE(a.max(1,   1), 1);
    QCOMPARE(a.max(-10,-5), -5);*/
};

void TestParseArgs::testParseArgs2()
{
	QStringList list = HelpersParseArgs::parse("test 5  123abc abc456 test test");
	QVERIFY(list.size() == 6);
};


void TestParseArgs::testParseArgs3()
{
	QStringList list = HelpersParseArgs::parse("\"test\" \"5\" 123 test test \"test1 test2\"");
};


void TestParseArgs::testParseArgs4()
{
	QStringList list = HelpersParseArgs::parse("\"test\" \"5\" 123 test test \"test1 test2\"");
};

void TestParseArgs::testParseArgs5()
{
	QStringList list = HelpersParseArgs::parse("\"test\" \"5\" 123 test test \"test1 test2\"");
};
