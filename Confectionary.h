//
// Created by andre on 2023/07/09.
//

#ifndef COS3711_ASS2_Q2_CONFECTIONARY_H
#define COS3711_ASS2_Q2_CONFECTIONARY_H
// Confectionery.h
#include "Stock.h"

class Confectionery : public Stock
{
private:
    int weight;

public:
    Confectionery() : Stock() {}
    Confectionery(QString i, int q, int w) : Stock(i, q), weight(w) {}

    int getWeight() { return weight; }
    void setWeight(int w) { weight = w; }

    QString toString() override;
};

#endif //COS3711_ASS2_Q2_CONFECTIONARY_H
