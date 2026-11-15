#pragma once

#include "node.h"

class Tore : public Node
{
protected:
	Vector m_center;
	double m_majorRadius;
	double m_minorRadius;

public:
	Tore(const Vector& c, double rMajor, double rMinor);
	double Value(const Vector& p) const;
};

