#include "tore.h"

Tore::Tore(const Vector& c, double rMajor, double rMinor) : m_center(c), m_majorRadius(rMajor), m_minorRadius(rMinor) {}

double Tore::Value(const Vector& p) const
{
    Vector q = p - m_center;

    double xz = std::sqrt(q[0] * q[0] + q[2] * q[2]) - m_majorRadius;

    return std::sqrt(xz * xz + q[1] * q[1]) - m_minorRadius;
}
