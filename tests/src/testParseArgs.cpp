#include <iostream>
#include "testParseArgs.h"
#include "../src/helpers/parseArgs.h"
#include <QStringList>
TestParseArgs::TestParseArgs(QObject *parent) :
    QObject(parent)
{
}

void TestParseArgs::testParse()
{
	QStringList list = HelpersParseArgs::parse("\"test\" \"5\" 123 test test \"test1 test2\"");

	// QCOMPARE(0, 1);
	// QVERIFY(1 == 1);

    /*Smart a;
    QCOMPARE(a.max(1,   0), 1);
    QCOMPARE(a.max(-1,  1), 1);
    QCOMPARE(a.max(4,   8), 8);
    QCOMPARE(a.max(0,   0), 0);
    QCOMPARE(a.max(1,   1), 1);
    QCOMPARE(a.max(-10,-5), -5);*/
};

// QTEST_APPLESS_MAIN(Test_ParseArgs)
