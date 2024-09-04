// Point.cpp
#include "Point.h"
#include <cmath>

// Default constructor
Point::Point() : x(0.0), y(0.0) {}

// Parameterized constructor
Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}

// Equality operator overload
bool Point::operator==(const Point& other) const {
    return (x == other.x) && (y == other.y);
}

// Subtraction operator overload to calculate distance between points
double Point::operator-(const Point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

// Getter for x coordinate
double Point::GetX() const {
    return x;
}

// Getter for y coordinate
double Point::GetY() const {
    return y;
}

// Setter for x coordinate
void Point::SetX(double xVal) {
    x = xVal;
}

// Setter for y coordinate
void Point::SetY(double yVal) {
    y = yVal;
}
