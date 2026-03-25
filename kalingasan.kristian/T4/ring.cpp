#include "ring.h"


Ring::Ring(const Point& center, int big, int small) : center_(center), bigRadius_(big), smallRadius_(small)
{
    if (small > big)
    {
        throw std::invalid_argument(INVALID_RADIUS_ERROR);
    }
}
double Ring::getArea()
{
    double bigArea = M_PI * bigRadius_ * bigRadius_;
    double smallArea = M_PI * smallRadius_ * smallRadius_;
    return bigArea - smallArea;
}
bool Ring::move(double x, double y)
{
    center_.pointMove(x, y);
    return true;
}
bool Ring::scale(size_t k)
{
    bigRadius_ *= k;
    smallRadius_ *= k;
    return true;
}
std::vector<Point> Ring::getBox()
{
    return { Point(center_.x_ - bigRadius_, center_.y_ - bigRadius_),
        Point(center_.x_ + bigRadius_,center_.y_ + bigRadius_) };
}
bool Ring::print(bool forComposite)
{
    Point center = getCenter();
    if (!forComposite)
    {
        std::cout << '[';
    }
    std::cout << getName() << ", (" << center.x_ << ", " << center.y_ << "), " << getArea();
    if (forComposite)
    {
        std::cout << ", ";
    }
    else
    {
        std::cout << ']';
    }
    std::cout << std::endl;
    return true;
}
