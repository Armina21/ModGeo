#pragma once

#include "node.h"
#include "color.h"
#include "box.h"

#include <vector>

struct BlobPoint
{
    Vector center;
    double radius;
    double weight;
    Color color;
};

struct BlobSegment
{
    Vector a;
    Vector b;
    double radius;
    double weight;
    Color color;
};

enum class BlobKernel
{
    Wyvill,
    Blinn
};

class BlobNode : public Node
{
private:
    std::vector<BlobPoint> points;
    std::vector<BlobSegment> segments;
    double threshold;

    BlobKernel kernel;
    double alpha;

    double Influence(double distance, double radius) const;
    double SegmentDistance(const Vector& p, const Vector& a, const Vector& b) const;

public:
    BlobNode(double threshold = 0.5, BlobKernel kernel = BlobKernel::Wyvill, double alpha = 4.0);

    void AddPoint(const Vector& center, double radius, Color c = Color(0.0, 0.0, 0.0), double weight = 1.0);

    void AddSegment(const Vector& a, const Vector& b, double radius, Color c = Color(0.0, 0.0, 0.0), double weight = 1.0);
    double Value(const Vector& p) const override;

    double LipschitzBound() const;

    Color EvaluateColor(const Vector& p) const;
    double NumericalLipschitzBound(const Box& box, int resolution, double h) const;
};
