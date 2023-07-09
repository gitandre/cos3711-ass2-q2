//
// Created by andre on 2023/07/09.
//

#ifndef COS3711_ASS2_Q2_STOCK_H
#define COS3711_ASS2_Q2_STOCK_H
#include <QString>

class Stock
{
protected:
    QString item;
    int quantity;

public:
    Stock() {}
    Stock(QString i, int q) : item(i), quantity(q) {}
    virtual ~Stock() {} // destructor

    virtual QString getItem() { return item; }
    virtual int getQuantity() { return quantity; }

    virtual void setItem(QString i) { item = i; }
    virtual void setQuantity(int q) { quantity = q; }

    virtual QString toString() = 0; // Pure virtual function makes Stock abstract
};
#endif //COS3711_ASS2_Q2_STOCK_H
