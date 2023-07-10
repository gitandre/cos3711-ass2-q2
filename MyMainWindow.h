#ifndef COS3711_ASS2_Q2_MYMAINWINDOW_H
#define COS3711_ASS2_Q2_MYMAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "Confectionary.h"
#include "ReadingMaterial.h"

class MyMainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

private slots:
    void addStockItem();
    void listConfectionary();
    void listReadingMaterial();

private:
    QListWidget* stocklistWidget;
    QList<Confectionary> confectioneries;
    QList<ReadingMaterial> readingMaterials;

    void updateMixedStockList();
    void populateListConfectionary();
    void populateReadingMaterials();
};
#endif
