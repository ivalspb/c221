#pragma once
#include "Shape.h"
#include <iostream>

class Rect :
    public Shape
{
    int l{}, r{}, t{}, b{};//left, right, top, bottom 
public:
    Rect() = default;
    Rect(int l, int r, int t, int b, Color c) :l(l), r(r), t(t), b(b), Shape{c} {};
    size_t getSq() const;
    void setClr(Color c);
    Color Clr() const;
    std::strong_ordering operator<=>(const Rect& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rect& r);
};

