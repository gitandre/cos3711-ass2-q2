//
// Created by andre on 2023/07/09.
//

#ifndef COS3711_ASS2_Q2_READINGMATERIAL_H
#define COS3711_ASS2_Q2_READINGMATERIAL_H
// ReadingMaterial.h
#include "Stock.h"

class ReadingMaterial : public Stock
{
private:
    QString frequency;

public:
    ReadingMaterial() : Stock() {}
    ReadingMaterial(QString i, int q, QString f) : Stock(i, q), frequency(f) {}
    ~ReadingMaterial() {} // destructor

    QString getFrequency() { return frequency; }
    void setFrequency(QString f) { frequency = f; }

    QString toString() override;
};
#endif //COS3711_ASS2_Q2_READINGMATERIAL_H
