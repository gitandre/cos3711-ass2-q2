//
// Created by andre on 2023/07/09.
//

#ifndef COS3711_ASS2_Q2_MAINWINDOW_H
#define COS3711_ASS2_Q2_MAINWINDOW_H
#include <QMainWindow>
#include <QListWidget>

#include "Confectionary.h"
#include "ReadingMaterial.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addStockItem();
    void listConfectionery();
    void listReadingMaterial();

private:
    QListWidget* listWidget;

    // Storage for demonstration purpose
    QList<Confectionery> confectioneries;
    QList<ReadingMaterial> readingMaterials;
};
#endif //COS3711_ASS2_Q2_MAINWINDOW_H
