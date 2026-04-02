#include "rectangle.h"

Rectangle::Rectangle(const Point& left, const Point& right) : leftBottom_(left), rightTop_(right)
{
    if (left.x_ > right.x_ || left.y_ > right.y_)
    {
        throw std::invalid_argument(INVALID_POINT_ERROR);
    }
}
double Rectangle::getArea()
{
    return (rightTop_.x_ - leftBottom_.x_) * (rightTop_.y_ - leftBottom_.y_);
}
Point Rectangle::getCenter()
{
    return Point((rightTop_.x_ + leftBottom_.x_) / 2, (rightTop_.y_ + leftBottom_.y_) / 2);
}
bool Rectangle::move(double x, double y)
{
    leftBottom_.pointMove(x, y);
    rightTop_.pointMove(x, y);
    return true;
}
bool Rectangle::scale(size_t k)
{
    double changeX = (k - 1) * (rightTop_.x_ - leftBottom_.x_)/2;
    double changeY = (k - 1) * (rightTop_.y_ - leftBottom_.y_)/2;
    rightTop_.pointMove(changeX, changeY);
    leftBottom_.pointMove(-1 * changeX, -1 * changeY);
    return true;
}
bool Rectangle::print(bool forComposite)
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
