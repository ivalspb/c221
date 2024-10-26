#include "ColoredRect.h"

Color ColoredRect::getColor() const
{
    return m_col;
}

double ColoredRect::getSquare() const
{
    return m_h*m_w;
}

std::ostream& operator<<(std::ostream& os, const ColoredRect& c)
{
    const char* colors[]{ "RED","GREEN","BLUE" };
    os <<"Rect:"
        << "\tx = " << c.m_x
        << "\ty = " << c.m_y
        << "\twidth = " << c.m_w
        << "\theight = " << c.m_h
        << "\tColor = " << colors[c.m_col];
    return os;
}

