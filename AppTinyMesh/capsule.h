#pragma once

#include "node.h"

class Capsule : public Node
{
protected:
	Vector m_a;
	Vector m_b;
	double m_radius;

public:
	Capsule(const Vector& a, const Vector& b, double radius);
	double Value(const Vector& p) const;
};

