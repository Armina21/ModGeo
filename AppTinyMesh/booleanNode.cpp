#include "booleanNode.h"
#include <algorithm>
#include <stdexcept>

BooleanNode::BooleanNode(
    std::unique_ptr<Node> a,
    std::unique_ptr<Node> b,
    BooleanOperation op
)
    : left(std::move(a)),
    right(std::move(b)),
    operation(op)
{
}

double BooleanNode::Value(const Vector& p) const
{
    double a = left->Value(p);
    double b = right->Value(p);

    switch (operation)
    {
    case BooleanOperation::Union:
        return Math::Min(a, b);

    case BooleanOperation::Intersection:
        return Math::Max(a, b);

    case BooleanOperation::Difference:
        return Math::Max(a, -b);
    }

    throw std::runtime_error("Unknown boolean operation");
}