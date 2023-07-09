// main.cpp
#include <QApplication>
#include <QListWidget>

#include "Confectionary.h"
#include "ReadingMaterial.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QListWidget listWidget;
    listWidget.setWindowTitle("Stock Information");

    Confectionery candy("Candy", 100, 50);
    ReadingMaterial book("Book", 50, "Monthly");

    new QListWidgetItem(candy.toString(), &listWidget);
    new QListWidgetItem(book.toString(), &listWidget);

    listWidget.show();

    return a.exec();
}