#include "ivector2.h"

IVector2::IVector2()
{
    X = 0;
    Y = 0;
}

IVector2::IVector2(const int& x, const int& y)
{
    X = x;
    Y = y;
}

IVector2::IVector2(const IVector2& other)
{
    X = other.X;
    Y = other.Y;
}

IVector2::~IVector2()
{
}

IVector2& IVector2::operator=(const IVector2& other)
{
    X = other.X;
    Y = other.Y;
    return *this;
}

IVector2& IVector2::operator+=(const IVector2& other)
{
    X += other.X;
    Y += other.Y;
    return *this;
}

IVector2& IVector2::operator-=(const IVector2& other)
{
    X -= other.X;
    Y -= other.Y;
    return *this;
}

IVector2& IVector2::operator*=(const int& other)
{
    X *= other;
    Y *= other;
    return *this;
}

IVector2& IVector2::operator/=(const int& other)
{
    X /= other;
    Y /= other;
    return *this;
}

const int& IVector2::GetX() const
{
    return X;
}
void IVector2::SetX(const int& x)
{
    X = x;
}

const int& IVector2::GetY() const
{
    return Y;
}

void IVector2::SetY(const int& y)
{
    Y = y;
}