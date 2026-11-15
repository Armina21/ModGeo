#include "sphere.h"

Sphere::Sphere(const Vector& c, double r) : m_center(c), m_radius(r) {}

double Sphere::Value(const Vector& p) const {
	 return Norm(p - m_center) - m_radius;
}
