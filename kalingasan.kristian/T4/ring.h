#ifndef RING_HPP
#define RING_HPP

#include "shape.h"

class Ring : public Shape
{
public:
    Ring(const Point& center, int big, int small);
    double getArea() override;
    Point getCenter() override { return center_; }
    bool move(double x, double y) override;
    bool scale(size_t k) override;
    std::string getName() override { return "RING"; }
    std::vector<Point> getBox() override;
    bool print(bool forComposite) override;
private:
    Point center_;
    int bigRadius_{ 0 };
    int smallRadius_{ 0 };
};

#endif
