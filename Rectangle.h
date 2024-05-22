#include <iostream>
#include "Point.h"

using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
private:
    Point startPoint;
    int width;
    int height;
public:
    Rectangle();
    Rectangle(const Point& startPoint, int width, int height);
    Rectangle(const Rectangle& other);
    Rectangle& operator +=(const Rectangle& other);
    Rectangle& operator -=(const Rectangle& other);
    friend Rectangle operator /(const Rectangle& rectangle1, const Rectangle& rectangle2);
    const Point& getStartPoint() const;
    void setStartPoint(const Point &startPoint);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    bool collisionDetection(const Rectangle& other) const;
};


#endif