#pragma once

#include <math.h> 

class IVector2
{
private:
    int X;
    int Y;

public:
    IVector2();
    IVector2(const int& x, const int& y);
    IVector2(const IVector2& other);
    ~IVector2();

    friend bool operator==(const IVector2& left, const IVector2& right)
    {
        return left.X == right.X && left.Y == right.Y;
    }

    friend bool operator!=(const IVector2& left, const IVector2& right)
    {
        return left.X != right.X || left.Y != right.Y;
    }

    friend IVector2 operator+(IVector2 left, const IVector2& right)
    {
        left.X += right.X;
        left.Y += right.Y;
        return left;
    }

    friend IVector2 operator-(IVector2 left, const IVector2& right)
    {
        left.X -= right.X;
        left.Y -= right.Y;
        return left;
    }

    friend IVector2 operator*(IVector2 left, const int& right)
    {
        left.X *= right;
        left.Y *= right;
        return left;
    }

    friend IVector2 operator/(IVector2 left, const int& right)
    {
        left.X /= right;
        left.Y /= right;
        return left;
    }

    IVector2& operator=(const IVector2& other);
    IVector2& operator+=(const IVector2& other);
    IVector2& operator-=(const IVector2& other);
    IVector2& operator*=(const int& other);
    IVector2& operator/=(const int& other);

    int GetX() const;
    void SetX(const int& x);

    int GetY() const;
    void SetY(const int& y);

    static double GetDistance(const IVector2& left, const IVector2& right)
    {
        double x_distance = pow(left.X - right.X ,2);
        double y_distance = pow(left.Y - right.Y ,2);
        return abs(sqrt(x_distance + y_distance));
    }
};