#include "boxSDF.h"
#include <algorithm>
#include <cmath>

BoxSDF::BoxSDF(const Vector& c, const Vector& size)
    : m_center(c), m_halfSize(size)
{
}

double BoxSDF::Value(const Vector& p) const
{
    Vector q = Abs(p - m_center) - m_halfSize;

    Vector outside(
        std::max(q[0], 0.0),
        std::max(q[1], 0.0),
        std::max(q[2], 0.0)
    );

    double inside = std::min(
        std::max(q[0], std::max(q[1], q[2])),
        0.0
    );

    return Norm(outside) + inside;
}