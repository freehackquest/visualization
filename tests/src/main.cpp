#include <QApplication>
#include <QTest>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "testParseArgs.h"

int main(int argc, char *argv[])
{
    // freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new TestParseArgs, argc, argv);
    /*cout << endl;
    QTest::qExec(new Test_QLineEdit, argc, argv);*/
    return 0;
}
