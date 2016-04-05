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
	QStringList list = HelpersParseArgs::parse("command 10,1 '#34'  123abc abc456  13.88 good");
	QVERIFY(list.size() == 7);
	QVERIFY(list[0] == "command");
	QVERIFY(list[1] == "10,1");
	QVERIFY(list[2] == "#34");
	QVERIFY(list[3] == "123abc");
	QVERIFY(list[4] == "abc456");
	QVERIFY(list[5] == "13.88");
	QVERIFY(list[6] == "good");
};

void TestParseArgs::testParseArgs3()
{
	QStringList list = HelpersParseArgs::parse("\"test\" \"7\" 123 third some \"test1 test2\" \"\"");
	QVERIFY(list.size() == 7);
	QVERIFY(list[0] == "test");
	QVERIFY(list[1] == "7");
	QVERIFY(list[2] == "123");
	QVERIFY(list[3] == "third");
	QVERIFY(list[4] == "some");
	QVERIFY(list[5] == "test1 test2");
	QVERIFY(list[6] == "");
};

void TestParseArgs::testParseArgs4()
{
	QStringList list = HelpersParseArgs::parse("\"test 5 123 test test test1 test2\"");
	QVERIFY(list.size() == 1);
	QVERIFY(list[0] == "test 5 123 test test test1 test2");
};

void TestParseArgs::testParseArgs5()
{
	QStringList list = HelpersParseArgs::parse("\"test \\\"5 123\" test test test1 test2\"");
	QVERIFY(list.size() == 5);
	QVERIFY(list[0] == "test \"5 123");
	QVERIFY(list[1] == "test");
	QVERIFY(list[2] == "test");
	QVERIFY(list[3] == "test1");
	QVERIFY(list[4] == "test2");
};

void TestParseArgs::testParseArgs6()
{
	QStringList list = HelpersParseArgs::parse("'test \"5 123' test test test1 test2\"");
	/*std::cout << list.size() << "\n";
	for(int i = 0; i < list.size(); i++){
		std::cout << list[i].toStdString() << "\n";
	}*/
	QVERIFY(list.size() == 5);
	QVERIFY(list[0] == "test \"5 123");
	QVERIFY(list[1] == "test");
	QVERIFY(list[2] == "test");
	QVERIFY(list[3] == "test1");
	QVERIFY(list[4] == "test2");
};

void TestParseArgs::testParseArgs7()
{
	QStringList list = HelpersParseArgs::parse("test 1 # hello kitty");
	QVERIFY(list.size() == 2);
	QVERIFY(list[0] == "test");
	QVERIFY(list[1] == "1");
};

void TestParseArgs::testParseArgs8()
{
	QStringList list = HelpersParseArgs::parse("test 1 '# hello kitty'");
	QVERIFY(list.size() == 3);
	QVERIFY(list[0] == "test");
	QVERIFY(list[1] == "1");
	QVERIFY(list[2] == "# hello kitty");
};

