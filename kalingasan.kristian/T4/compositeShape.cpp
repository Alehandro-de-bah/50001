#include "compositeShape.h"

bool CompositeShape::addShape(std::unique_ptr<Shape> shape)
{
    shapes_.push_back(std::move(shape));
    ++count_;
    return true;
}
double CompositeShape::getArea()
{
    double area = 0;
    for (size_t i = 0; i < count_; i++)
    {
        area += shapes_[i]->getArea();
    }
    return area;
}
Point CompositeShape::getCenter()
{
    std::vector<Point> points = getBox();
    double centerX = (points[0].x_ + points[1].x_) / 2;
    double centerY = (points[0].y_ + points[1].y_) / 2;
    return Point(centerX, centerY);
}
bool CompositeShape::move(double x, double y)
{
    for (size_t i = 0; i < count_; i++)
    {
        shapes_[i]->move(x, y);
    }
    return true;
}
bool CompositeShape::scale(size_t k)
{
    for (size_t i = 0; i < count_; i++)
    {
        Point oldCenter = shapes_[i]->getCenter();
        Point center = getCenter();
        shapes_[i]->move((k - 1) * (oldCenter.x_ - center.x_), (k - 1) * (oldCenter.y_ - center.y_));
        shapes_[i]->scale(k);
    }
    return true;
}
std::vector<Point> CompositeShape::getBox()
{
    if (count_ == 0)
    {
        return { Point(0, 0), Point(0, 0) };
    }
    std::vector<Point> points = shapes_[0]->getBox();
    double minX = points[0].x_;
    double minY = points[0].y_;
    double maxX = points[1].x_;
    double maxY = points[1].y_;
    for (size_t i = 1; i < count_; i++)
    {
        points = shapes_[i]->getBox();
        minX = points[0].x_ < minX ? points[0].x_ : minX;
        minY = points[0].y_ < minY ? points[0].y_ : minY;
        maxX = points[1].x_ > maxX ? points[1].x_ : maxX;
        maxY = points[1].y_ > maxY ? points[1].y_ : maxY;
    }
    return { Point(minX, minY), Point(maxX, maxY) };
}
bool CompositeShape::print(bool forComposite)
{
    Point center = getCenter();
    if (!forComposite)
    {
        std::cout << '[';
    }
    std::cout << getName() << ", (" << center.x_ << ", " << center.y_ << "), " << getArea();
    if (forComposite)
    {
        return true;
    }
    else
    {
        std::cout << ':' << std::endl;
    }
    for (size_t i = 0; i < count_; i++)
    {
        shapes_[i]->print(true);
    }
    std::cout << ']' << std::endl;
    return true;
}
