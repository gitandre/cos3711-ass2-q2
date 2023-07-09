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

    Confectionery getConfectionery();
    ReadingMaterial getReadingMaterial();
    QString getType();

private:
    QLineEdit* itemEdit;
    QSpinBox* quantitySpin;
    QLineEdit* extraEdit;
    QComboBox* typeBox;
};
#endif //COS3711_ASS2_Q2_STOCKDIALOG_H
