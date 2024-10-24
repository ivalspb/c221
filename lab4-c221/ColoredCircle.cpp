#include "ColoredCircle.h"

Color ColoredCircle::getColor() const
{
    return m_col;
}

double ColoredCircle::getSquare() const
{
    return M_PI*m_r;
}

int ColoredCircle::getRadius() const
{
    return m_r;
}

double ColoredCircle::getDist() const
{
    return sqrt(m_x*m_x+m_y*m_y);
}

std::ostream& operator<<(std::ostream& os, const ColoredCircle& c)
{
    const char* colors[]{ "RED","GREEN","BLUE" };
    os << "x = " << c.m_x
       << "\ty = " << c.m_y
       << "\tr = " << c.m_r
       << "\tColor = " << colors[c.m_col];
        return os;
}
