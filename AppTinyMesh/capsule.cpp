#include "capsule.h"

Capsule::Capsule(const Vector& a, const Vector& b, double radius) : m_a(a), m_b(b), m_radius(radius) {}
double Capsule::Value(const Vector& p) const
{
    Vector ba = m_b - m_a;
    Vector pa = p - m_a;

    double h = Math::Clamp(
        (pa * ba) / (ba * ba),
        0.0,
        1.0
    );

    return Norm(pa - ba * h) - m_radius;
}
