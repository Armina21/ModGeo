#pragma once

#include "node.h"

class Sphere : public Node{
protected:
	Vector m_center;
	double m_radius;

public:
	Sphere(const Vector& c, double r);	
	double Value(const Vector& p) const override;

};

