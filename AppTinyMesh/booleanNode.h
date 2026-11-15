#pragma once

#include "node.h"
#include <memory>

enum class BooleanOperation
{
    Union,
    Intersection,
    Difference
};

class BooleanNode : public Node
{
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    BooleanOperation operation;

public:
    BooleanNode(
        std::unique_ptr<Node> a,
        std::unique_ptr<Node> b,
        BooleanOperation op
    );

    double Value(const Vector& p) const override;
};