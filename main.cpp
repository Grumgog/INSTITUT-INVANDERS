#include "widget.h"
#include <QApplication>
#include <iostream>
#include <UserClass/npc.h>



#include <QWidget>
#include <QGLWidget>
#include <QMainWindow>


using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //w.showFullScreen();

/*
    QMainWindow mainW;
    mainW.setCentralWidget(&w);
    mainW.show();

    mainW.setGeometry(10, 10, 611, 536);
    mainW.setMouseTracking(true);
*/
    w.show();

    return a.exec();
}
