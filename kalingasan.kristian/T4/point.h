#ifndef POINT_HPP
#define POINT_HPP

struct Point
{
    double x_{ 0 };
    double y_{ 0 };
    Point(double x = 0, double y = 0) : x_(x), y_(y) {} // конструктор точки
    bool pointMove(double x, double y) { x_ += x; y_ += y; return true; } // метод для перемещения точки
};

#endif
