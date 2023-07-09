//
// Created by andre on 2023/07/09.
//
// Confectionery.cpp
#include "Confectionary.h"

QString Confectionery::toString() {
    return "Confectionery Item: " + item + ", Quantity: " + QString::number(quantity) + ", Weight: " + QString::number(weight);
}