//
// Created by andre on 2023/07/09.
//

#ifndef COS3711_ASS2_Q2_STOCKDIALOG_H
#define COS3711_ASS2_Q2_STOCKDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>

#include "Confectionary.h"
#include "ReadingMaterial.h"

class StockDialog : public QDialog
{
Q_OBJECT

public:
    explicit StockDialog(QWidget *parent = nullptr);

    Confectionary getConfectionary();
    ReadingMaterial getReadingMaterial();
    QString getType();
    QString getItem();
    int getQuantity();
    QString getExtra();

private:
    QLineEdit* itemEdit;
    QSpinBox* quantitySpin;
    QLineEdit* extraEdit;
    QComboBox* typeBox;
};
#endif //COS3711_ASS2_Q2_STOCKDIALOG_H
