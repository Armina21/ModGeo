#pragma once
#include "Node.h"

class BoxSDF : public Node
{
private:
    Vector m_center;
    Vector m_halfSize;

public:
    BoxSDF(const Vector& c, const Vector& size);

    double Value(const Vector& p) const override;
};