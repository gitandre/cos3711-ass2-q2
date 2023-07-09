//
// Created by andre on 2023/07/09.
//
// ReadingMaterial.cpp
#include "ReadingMaterial.h"

QString ReadingMaterial::toString() {
    return "Reading Material: " + item + ", Quantity: " + QString::number(quantity) + ", Frequency: " + frequency;
}