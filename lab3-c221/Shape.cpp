#include "Shape.h"

std::ostream& operator<<(std::ostream& os, const Shape& s)
{
    const char* clr[]{ "Red", "Green", "Blue" };
    os << "\tColor = " << clr[s.c];
    return os;
}

void Shape::setClr(const Color& new_clr)
{
    c = new_clr;
}

Color Shape::Clr() const
{
    return c;
}
