#include <QMenuBar>
#include <QMessageBox>
#include "MyMainWindow.h"
#include "MyStockDialog.h"
#include "ConfectReadingMatFactory.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
        QMainWindow(parent),
        stocklistWidget(new QListWidget(this))
{
    setCentralWidget(stocklistWidget);
    resize(800, 600);

    // Setup menu items---------------------------------------------------------------------------------------------------
    // Stock
    QMenu* stockMenu = menuBar()->addMenu(tr("Stock"));
    QAction* addStockAction = stockMenu->addAction(tr("Add stock item"));

    // List
    QMenu* listMenu = menuBar()->addMenu(tr("List Stock"));
    QAction* listConfectionaryAction = listMenu->addAction(tr("List Confectionary Items"));
    QAction* listReadingMaterialAction = listMenu->addAction(tr("List Reading Material Items"));

    // Slots and signals
    connect(addStockAction, &QAction::triggered, this, &MyMainWindow::addStockItem);
    connect(listConfectionaryAction, &QAction::triggered, this, &MyMainWindow::listConfectionary);
    connect(listReadingMaterialAction, &QAction::triggered, this, &MyMainWindow::listReadingMaterial);

    // Show the initial/empty stock list
    updateMixedStockList();

}

// Destructor
MyMainWindow::~MyMainWindow()
{
    delete stocklistWidget;
}

// Add a new stock item of the 2 types
void MyMainWindow::addStockItem()
{

    MyStockDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {

        // Using the factory pattern to create confectionary or reading material
        ConfectReadingMatFactory factory;
        auto stock = factory.create(dialog.getType(), dialog.getItem(), dialog.getQuantity(), dialog.getExtra());

        if (auto confectionery = dynamic_cast<Confectionary*>(stock.get())) {
            confectioneries.append(*confectionery);
            QMessageBox::information(this, "Information", "Confectionary item saved OK");
        }
        else if (auto readingMaterial = dynamic_cast<ReadingMaterial*>(stock.get())) {
            readingMaterials.append(*readingMaterial);
            QMessageBox::information(this, "Information", "ReadingMaterial item saved OK");
        }
    }

    //Display all the stock items after a successful save
    updateMixedStockList();
}

void MyMainWindow::listConfectionary()
{
    // Show just confectionary items
    stocklistWidget->clear();
    populateListConfectionary();

}

void MyMainWindow::populateListConfectionary() {

    // Handle zero qty
    if (confectioneries.size() == 0){
        stocklistWidget->addItem("Confectionary Items: 0");
        return;
    }

    // Show just confectionary items -> by building a new list
    for(int i=0; i < confectioneries.size(); i++){
        stocklistWidget->addItem(confectioneries[i].toString());
    }
    stocklistWidget->show();
}

void MyMainWindow::listReadingMaterial()
{
    // Show just reading materials items
    stocklistWidget->clear();
    populateReadingMaterials();
}

void MyMainWindow::populateReadingMaterials() {

    // Handle zero qty
    if (readingMaterials.size() == 0){
        stocklistWidget->addItem("Reading Material Items: 0");
        return;
    }

    // Show just reading materials items -> by building a new list
    for(int i=0; i < readingMaterials.size(); i++){
        stocklistWidget->addItem(readingMaterials[i].toString());
    }
    stocklistWidget->show();
}

void MyMainWindow::updateMixedStockList() {

    // Show both types in one list for after a save
    stocklistWidget->clear();
    populateListConfectionary();
    populateReadingMaterials();
}