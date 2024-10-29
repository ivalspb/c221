#include "Rect.h"
#include <math.h>

size_t Rect::getSq() const
{
    return abs(l-r)*abs(t-b);
}

std::strong_ordering Rect::operator<=>(const Shape& other) const noexcept
{
    if (this->getSq() == other.getSq())
        return this->Shape::operator<=>(other);
    else return this->getSq() <=> other.getSq();
}

std::strong_ordering Rect::operator<=>(const Rect& other) const
{
    if (this->getSq() == other.getSq()) 
        return this->Shape::operator<=>(other);
    else return this->getSq() <=> other.getSq();
}   

std::ostream& operator<<(std::ostream& os, const Rect& r)
{
    os << "left = " << r.l
        << "\tright = " << r.r
        << "\ttop = " << r.t
        << "\tbottom = " << r.b
        <<  static_cast<const Shape&>(r);
    return os;
}
