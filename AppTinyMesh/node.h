#pragma once

#include "mathematics.h"

class Node
{
public:
    virtual ~Node() = default;

    virtual double Value(const Vector& p) const = 0;
};