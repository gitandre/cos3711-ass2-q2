#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication myApp(argc, argv);
    MainWindow myMainWindow;
    myMainWindow.setWindowTitle("COS3711 - Assignment 2 - Question 2");
    myMainWindow.show();
    return myApp.exec();
}