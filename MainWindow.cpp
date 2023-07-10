#include <QMenuBar>
#include <QMessageBox>
#include "MainWindow.h"
#include "StockDialog.h"
#include "ConfectionaryReadingMatFactory.h"

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
    QAction* listConfectionaryAction = listMenu->addAction(tr("List Confectionary Items"));
    QAction* listReadingMaterialAction = listMenu->addAction(tr("List Reading Material Items"));

    // Slots and signals
    connect(addStockAction, &QAction::triggered, this, &MainWindow::addStockItem);
    connect(listConfectionaryAction, &QAction::triggered, this, &MainWindow::listConfectionary);
    connect(listReadingMaterialAction, &QAction::triggered, this, &MainWindow::listReadingMaterial);

}

MainWindow::~MainWindow()
{
    delete stocklistWidget;
}

void MainWindow::addStockItem()
{

    StockDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {

        // Using the factory pattern to create confectionary or reading material
        ConfectionaryReadingMatFactory factory;
        auto stock = factory.create(dialog.getType(), dialog.getItem(), dialog.getQuantity(), dialog.getExtra());

        if (auto confectionery = dynamic_cast<Confectionary*>(stock.get())) {
            confectioneries.append(*confectionery);
            QMessageBox::information(this, "Information", "Confectionary item added OK");
        }
        else if (auto readingMaterial = dynamic_cast<ReadingMaterial*>(stock.get())) {
            readingMaterials.append(*readingMaterial);
            QMessageBox::information(this, "Information", "ReadingMaterial item added OK");
        }
    }

    //Display all the stock items after a successful save
    updateMixedStockList();
}

void MainWindow::listConfectionary()
{
    // Show just confectionary items
    stocklistWidget->clear();
    populateListConfectionary();

}

void MainWindow::populateListConfectionary() {

    // Show just confectionary items -> by building a new list
    for(int i=0; i < confectioneries.size(); i++){
        stocklistWidget->addItem(confectioneries[i].toString());
    }
    stocklistWidget->show();
}

void MainWindow::listReadingMaterial()
{
    // Show just reading materails items
    stocklistWidget->clear();
    populateReadingMaterials();
}

void MainWindow::populateReadingMaterials() {

    // Show just reading materails items -> by building a new list
    for(int i=0; i < readingMaterials.size(); i++){
        stocklistWidget->addItem(readingMaterials[i].toString());
    }
    stocklistWidget->show();
}

void MainWindow::updateMixedStockList() {

    // Show both types in one list for after a save
    stocklistWidget->clear();
    populateListConfectionary();
    populateReadingMaterials();
}
