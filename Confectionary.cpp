//
// Created by andre on 2023/07/09.
//
// Confectionary.cpp
#include "Confectionary.h"

QString Confectionary::toString() {
    return "Confectionary Item: " + item + ", Quantity: " + QString::number(quantity) + ", Weight: " + QString::number(weight);
}