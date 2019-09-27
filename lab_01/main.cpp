#include <QApplication>
#include <stdlib.h>
#include <stdio.h>
#include "mainwindow.h"
#include "model.h"
#include "actiongeometry.h"
#include "action.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
