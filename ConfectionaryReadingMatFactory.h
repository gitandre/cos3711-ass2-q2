//
// Created by andre on 2023/07/10.
//

#ifndef COS3711_ASS2_Q2_CONFECTIONARYREADINGMATFACTORY_H
#define COS3711_ASS2_Q2_CONFECTIONARYREADINGMATFACTORY_H
#include "StockFactory.h"

class ConfectionaryReadingMatFactory : public StockFactory
{
public:
    std::unique_ptr<Stock> create(QString type, QString name, int quantity, QString extra) override
    {
        if (type == "Confectionary") {
            return std::make_unique<Confectionary>(name, quantity, extra.toInt());
        }
        else if (type == "ReadingMaterial") {
            return std::make_unique<ReadingMaterial>(name, quantity, extra);
        }
        else {
            throw std::runtime_error("Invalid type.");
        }
    }
};
#endif //COS3711_ASS2_Q2_CONFECTIONARYREADINGMATFACTORY_H
