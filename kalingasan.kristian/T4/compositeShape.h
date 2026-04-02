#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.h"
#include "ring.h"
#include "rectangle.h"

class CompositeShape : public Shape
{
public:
    bool addShape(std::unique_ptr<Shape> shape);
    double getArea() override;
    Point getCenter() override;
    bool move(double x, double y) override;
    bool scale(size_t k) override;
    std::string getName() override { return "COMPOSITE"; }
    std::vector<Point> getBox() override;
    bool print(bool forComposite) override;
private:
    std::vector<std::unique_ptr<Shape>> shapes_; // вектор фигур
    size_t count_{ 0 }; // количество фигур
};

#endif
