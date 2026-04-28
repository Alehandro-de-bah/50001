#include "polygon.h"

namespace bahurov
{
    // Перегрузка оператора ввода для структуры Polygon
    std::istream& operator>>(std::istream& in, Polygon& polygon)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        size_t vertexes = 0;
        in >> vertexes;

        if (!in || vertexes < 3)
        {
            in.setstate(std::ios::failbit);
            return in;
        }

        Polygon input;
        std::generate_n(std::back_inserter(input.points), vertexes,
            [&in]()
            {
                Point point;
                in >> DelimetrIO{ ' ' } >> point;
                return point;
            }
        );

        if (in)
        {
            polygon = std::move(input);
        }
        return in;
    }
}
