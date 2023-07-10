//
// Created by andre on 2023/07/10.
//

#ifndef COS3711_ASS2_Q2_STOCKFACTORY_H
#define COS3711_ASS2_Q2_STOCKFACTORY_H
#include <memory>

#include "Confectionary.h"
#include "ReadingMaterial.h"

class StockFactory
{
public:
    virtual ~StockFactory() {}
    virtual std::unique_ptr<Stock> create(QString type, QString name, int quantity, QString extra) = 0;
};
#endif //COS3711_ASS2_Q2_STOCKFACTORY_H
