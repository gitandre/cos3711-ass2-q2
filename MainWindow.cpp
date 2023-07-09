
#include <QMenuBar>
#include <QMessageBox>
#include "MainWindow.h"
#include "StockDialog.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        listWidget(new QListWidget(this))
{
    setCentralWidget(listWidget);
    resize(800, 600);

    // Setup menu items
    QMenu* stockMenu = menuBar()->addMenu(tr("Stock"));
    QAction* addStockAction = stockMenu->addAction(tr("Add stock item"));
    connect(addStockAction, &QAction::triggered, this, &MainWindow::addStockItem);

    QMenu* listMenu = menuBar()->addMenu(tr("List"));
    QAction* listConfectioneryAction = listMenu->addAction(tr("List Confectionery"));
    QAction* listReadingMaterialAction = listMenu->addAction(tr("List Reading Material"));
    connect(listConfectioneryAction, &QAction::triggered, this, &MainWindow::listConfectionery);
    connect(listReadingMaterialAction, &QAction::triggered, this, &MainWindow::listReadingMaterial);



//    Confectionery candy("Candy", 100, 50);
//    Confectionery buns("Buns", 123, 50);
//    Confectionery gateux("gateux", 432, 50);
//    ReadingMaterial book("Book", 50, "Monthly");
//
//    confectioneries.append(candy);
//    readingMaterials.append(book);
//
//    listWidget->clear();
//    for(int i=0;i < confectioneries.size();i++){
//        listWidget->addItem(confectioneries[i].toString());
//    }
//    listWidget->show();
}

MainWindow::~MainWindow()
{
    delete listWidget;
}

void MainWindow::addStockItem()
{

    StockDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.getType() == "Confectionery") {
            confectioneries.append(dialog.getConfectionery());
            QMessageBox::information(this, "Information", "Connfectionary item added OK");

        } else if (dialog.getType() == "Reading Material") {
            readingMaterials.append(dialog.getReadingMaterial());
            QMessageBox::information(this, "Information", "Readingmaterial item added OK");
        }
    }
}

void MainWindow::listConfectionery()
{

    listWidget->clear();
    for(int i=0;i < confectioneries.size();i++){
        listWidget->addItem(confectioneries[i].toString());
    }
    listWidget->show();

}

void MainWindow::listReadingMaterial()
{
    listWidget->clear();
    for(int i=0;i < readingMaterials.size();i++){
        listWidget->addItem(readingMaterials[i].toString());
    }
    listWidget->show();
}