#pragma once

#include <math.h> 

/**
 * Basic vector class that uses integers instead of doubles (hence the I infront of Vector2)
 */
class IVector2
{
protected:
    /**
     * X coordinate of the vector
     */
    int X;

    /**
     * Y coordinate of the vector
     */
    int Y;

public:
    /**
     * Default constructor
     * 
     * X and Y will be 0,0
     */
    IVector2();

    /**
     * Constructor that creates a new Vector with given coordinates
     * 
     * @param x X coordinate of the vector
     * @param y Y coordinate of the vector
     */
    IVector2(const int& x, const int& y);

    /**
     * Copy constructor
     * 
     * @param other Vector to copy from
     */
    IVector2(const IVector2& other);

    /**
     * Default destructor
     */
    ~IVector2();

    /**
     * Overloaded == operator, check if X and Y coordinates of two Vectors are the same.
     * 
     * @param left Vector to compare
     * @param right Vector to compare
     * @return Returns true if the vectors are equal, false otherwise
     */
    friend bool operator==(const IVector2& left, const IVector2& right)
    {
        return left.X == right.X && left.Y == right.Y;
    }

    /**
     * Overloaded != operator, check if two vectors are different.
     * 
     * @param left Vector to compare
     * @param right Vector to compare
     * @return Returns true if the vectors are not equal, false otherwise
     */
    friend bool operator!=(const IVector2& left, const IVector2& right)
    {
        return left.X != right.X || left.Y != right.Y;
    }

    /**
     * Adds the right vector from the left one and returns it
     * 
     * @param left Vector to add
     * @param right Vector to add
     * @return Returns the modified left Vector
     */
    friend IVector2 operator+(IVector2 left, const IVector2& right)
    {
        left.X += right.X;
        left.Y += right.Y;
        return left;
    }

    /**
     * Substracts the right vector from the left one and returns it
     * 
     * @param left Vector to add
     * @param right Vector to add
     * @return Returns the modified left Vector
     */
    friend IVector2 operator-(IVector2 left, const IVector2& right)
    {
        left.X -= right.X;
        left.Y -= right.Y;
        return left;
    }

    /**
     * Multiplies the vector by given number
     * 
     * @param left Vector to add
     * @param right integer to multiply by
     * @return Returns the modified left Vector
     */
    friend IVector2 operator*(IVector2 left, const int& right)
    {
        left.X *= right;
        left.Y *= right;
        return left;
    }

    /**
     * Divides the vector by given number
     * 
     * @param left Vector to add
     * @param right integer to divide by
     * @return Returns the modified left Vector
     */
    friend IVector2 operator/(IVector2 left, const int& right)
    {
        left.X /= right;
        left.Y /= right;
        return left;
    }

    /**
     * Copies the values of another Vector
     * 
     * @param other Vector to copy from
     * @return Reference to original vector
     */
    IVector2& operator=(const IVector2& other);

    /**
     * Adds another vector to this vector
     * 
     * @param other Vector to add from
     * @return Reference to original vector
     */
    IVector2& operator+=(const IVector2& other);

    /**
     * Substracts another vector from this vector
     * 
     * @param other Vector used for substracting
     * @return Reference to original vector
     */
    IVector2& operator-=(const IVector2& other);

    /**
     * Multiplies this vector by given integer
     * 
     * @param other Integer to multiply by
     * @return Reference to original vector
     */
    IVector2& operator*=(const int& other);

    /**
     * Divides this vector by given integer
     * 
     * @param other Integer to divide by
     * @return Reference to original vector
     */
    IVector2& operator/=(const int& other);

    /**
     * Returns the X coordinate
     * 
     * @return Returns the X coordinate
     */
    const int& GetX() const;

    /**
     * Sets the value of X coordinate
     * 
     * @param x Value to be set
     */
    void SetX(const int& x);

    /**
     * Returns the Y coordinate
     * 
     * @return Returns the Y coordinate
     */
    const int& GetY() const;

    /**
     * Sets the value of Y coordinate
     * 
     * @param y Value to be set
     */
    void SetY(const int& y);


    /**
     * Calculates and returns the distance between two vectors.
     * 
     * @param left Input Vector
     * @param right Input Vector
     * @return Distance between the vectors
     */
    static double GetDistance(const IVector2& left, const IVector2& right)
    {
        double x_distance = pow(left.X - right.X ,2);
        double y_distance = pow(left.Y - right.Y ,2);
        return abs(sqrt(x_distance + y_distance));
    }
};