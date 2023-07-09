#include <QMenuBar>
#include <QMessageBox>
#include "MainWindow.h"
#include "StockDialog.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        stocklistWidget(new QListWidget(this))
{
    setCentralWidget(stocklistWidget);
    resize(800, 600);

    // Setup menu items
    QMenu* stockMenu = menuBar()->addMenu(tr("Stock"));
    QAction* addStockAction = stockMenu->addAction(tr("Add stock item"));

    QMenu* listMenu = menuBar()->addMenu(tr("List Stock"));
    QAction* listConfectioneryAction = listMenu->addAction(tr("List Confectionery Items"));
    QAction* listReadingMaterialAction = listMenu->addAction(tr("List Reading Material Items"));

    // Slots and signals
    connect(addStockAction, &QAction::triggered, this, &MainWindow::addStockItem);
    connect(listConfectioneryAction, &QAction::triggered, this, &MainWindow::listConfectionery);
    connect(listReadingMaterialAction, &QAction::triggered, this, &MainWindow::listReadingMaterial);

}

MainWindow::~MainWindow()
{
    delete stocklistWidget;
}

void MainWindow::addStockItem()
{
    // Show the stock dialog and then based on selected save the item to the appropriate list
    StockDialog myStockDialog(this);
    if (myStockDialog.exec() == QDialog::Accepted) {
        if (myStockDialog.getType() == "Confectionery") {
            confectioneries.append(myStockDialog.getConfectionery());
            QMessageBox::information(this, "Information", "Confectionary item added OK");

        } else if (myStockDialog.getType() == "Reading Material") {
            readingMaterials.append(myStockDialog.getReadingMaterial());
            QMessageBox::information(this, "Information", "ReadingMaterial item added OK");
        }
    }
}

void MainWindow::listConfectionery()
{
    // clear and append confectioneries items for display purposes
    stocklistWidget->clear();
    for(int i=0;i < confectioneries.size();i++){
        stocklistWidget->addItem(confectioneries[i].toString());
    }
    stocklistWidget->show();

}

void MainWindow::listReadingMaterial()
{
    // clear and append readingMaterials items for display purposes
    stocklistWidget->clear();
    for(int i=0;i < readingMaterials.size();i++){
        stocklistWidget->addItem(readingMaterials[i].toString());
    }
    stocklistWidget->show();
}