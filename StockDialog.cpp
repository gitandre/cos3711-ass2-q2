//
// Created by andre on 2023/07/09.
//
#include <QFormLayout>
#include <QPushButton>
#include <QDialogButtonBox>

#include "StockDialog.h"

StockDialog::StockDialog(QWidget *parent) :
        QDialog(parent),
        itemEdit(new QLineEdit(this)),
        quantitySpin(new QSpinBox(this)),
        extraEdit(new QLineEdit(this)),
        typeBox(new QComboBox(this))
{
    typeBox->addItem("Confectionary");
    typeBox->addItem("ReadingMaterial");

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Type", typeBox);
    formLayout->addRow("Item", itemEdit);
    formLayout->addRow("Quantity", quantitySpin);
    formLayout->addRow("Extra (Weight/Frequency)", extraEdit);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
    setWindowTitle("Capture Stock");
}

Confectionary StockDialog::getConfectionary()
{
    return Confectionary(itemEdit->text(), quantitySpin->value(), extraEdit->text().toInt());
}

ReadingMaterial StockDialog::getReadingMaterial()
{
    return ReadingMaterial(itemEdit->text(), quantitySpin->value(), extraEdit->text());
}

QString StockDialog::getType()
{
    return typeBox->currentText();
}

QString StockDialog::getItem() {
    return itemEdit->text();
}

int StockDialog::getQuantity() {
    return quantitySpin->value();
}

QString StockDialog::getExtra() {
    return extraEdit->text();
}
