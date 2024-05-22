#include <iostream>
#include <cmath>

using namespace std;

#ifndef POINT_H
#define POINT_H

//point class prototype

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point(const Point& other);
    friend Point operator +(const Point& point1, const Point& point2);
    friend Point operator -(const Point& point1, const Point& point2);
    Point& operator /=(int num);
    bool operator >=(const Point& point2) const;
    Point& operator = (const Point& other);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

};


#endif
