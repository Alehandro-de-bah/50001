#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(const Point& left, const Point& right);
    double getArea() override;
    Point getCenter() override;
    bool move(double x, double y) override;
    bool scale(size_t k) override;
    std::string getName() override { return "RECTANGLE"; }
    std::vector<Point> getBox() override { return { leftBottom_, rightTop_ }; }
    bool print(bool forComposite) override;
private:
    Point leftBottom_;
    Point rightTop_;
};

#endif
