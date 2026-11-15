#include "blobNode.h"

double BlobNode::Influence(double distance, double radius) const
{
    if (radius <= 0.0)
        return 0.0;

    double u = distance / radius;

    if (kernel == BlobKernel::Wyvill)
    {
        if (u >= 1.0)
            return 0.0;

        double v = 1.0 - u * u;
        return v * v * v;
    }

    // Noyau de Blinn
    return std::exp(-alpha * u * u);
}

double BlobNode::SegmentDistance(const Vector& p, const Vector& a, const Vector& b) const
{
    Vector ab = b - a;
    Vector ap = p - a;

    double lengthSquared = SquaredNorm(ab);

    // Cas d'un segment dégénéré : il devient un point.
    if (lengthSquared < 1e-12)
        return Norm(ap);

    double t = Math::Clamp(
        (ap * ab) / lengthSquared
    );

    Vector closest = a + ab * t;

    return Norm(p - closest);
}

BlobNode::BlobNode(double threshold, BlobKernel kernel, double alpha): threshold(threshold), kernel(kernel), alpha(alpha) {}

void BlobNode::AddPoint(const Vector& center, double radius, Color c, double weight)
{
    points.push_back({ center, radius, weight, c });
}

void BlobNode::AddSegment(const Vector& a, const Vector& b, double radius, Color c, double weight)
{
    if (radius <= 0.0)
        return;

    segments.push_back({ a, b, radius, weight, c });
}

double BlobNode::Value(const Vector& p) const 
{
    double field = 0.0;

    for (const auto& point : points)
    {
        double d = Norm(p - point.center);
        double u = d / point.radius;

        if (u < 1.0)
        {
            double influence = 1.0 - u * u;
            influence = influence * influence * influence;

            field += point.weight * influence;
        }
    }

    // Influence des segments
    for (const auto& segment : segments)
    {
        double distance = SegmentDistance(
            p,
            segment.a,
            segment.b
        );

        field += segment.weight *
            Influence(distance, segment.radius);
    }

    return threshold - field;
}

double BlobNode::LipschitzBound() const
{
    const double K = 96.0 / (25.0 * std::sqrt(5.0));

    double L = 0.0;

    // Contribution des points
    for (const auto& point : points)
    {
        L += K * std::abs(point.weight) / point.radius;
    }

    // Contribution des segments
    for (const auto& segment : segments)
    {
        L += K * std::abs(segment.weight) / segment.radius;
    }

    return L;
}

Color BlobNode::EvaluateColor(const Vector& p) const
{
    Color result{ 0.0, 0.0, 0.0 };
    double totalWeight = 0.0;

    for (const auto& point : points)
    {
        double d = Norm(p - point.center);
        double influence = point.weight *
            Influence(d, point.radius);

        result[0] += influence * point.color[0];
        result[1] += influence * point.color[1];
        result[2] += influence * point.color[2];

        totalWeight += influence;
    }

    for (const auto& segment : segments)
    {
        double d = SegmentDistance(p, segment.a, segment.b);
        double influence = segment.weight *
            Influence(d, segment.radius);

        result[0] += influence * segment.color[0];
        result[1] += influence * segment.color[1];
        result[2] += influence * segment.color[2];

        totalWeight += influence;
    }

    /*if (std::abs(totalWeight) < 1e-12)
        return { 0.0, 0.0, 0.0 };*/

    result[0] /= totalWeight;
    result[1] /= totalWeight;
    result[2] /= totalWeight;

    return result;
}

double BlobNode::NumericalLipschitzBound(
    const Box& box,
    int resolution,
    double h) const
{
    double maxGradient = 0.0;

    Vector min = box[0];
    Vector max = box[1];

    for (int i = 0; i < resolution; i++)
    {
        for (int j = 0; j < resolution; j++)
        {
            for (int k = 0; k < resolution; k++)
            {
                Vector p(
                    min[0] + i * (max[0] - min[0]) / (resolution - 1),
                    min[1] + j * (max[1] - min[1]) / (resolution - 1),
                    min[2] + k * (max[2] - min[2]) / (resolution - 1)
                );

                Vector dx(h, 0.0, 0.0);
                Vector dy(0.0, h, 0.0);
                Vector dz(0.0, 0.0, h);

                double gx = (Value(p + dx) - Value(p - dx)) / (2.0 * h);
                double gy = (Value(p + dy) - Value(p - dy)) / (2.0 * h);
                double gz = (Value(p + dz) - Value(p - dz)) / (2.0 * h);

                double gradient = std::sqrt(
                    gx * gx + gy * gy + gz * gz
                );

                maxGradient = std::max(maxGradient, gradient);
            }
        }
    }

    return maxGradient;
}
