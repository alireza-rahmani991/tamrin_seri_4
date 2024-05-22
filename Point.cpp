#include "Point.h"

//no argument constructor that sets all values to zero
Point::Point() {
    x= 0;
    y = 0;
}

//two argument constructor that sets the given value to x and y
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

//copy constructor
Point::Point(const Point &other) {
    this->x = other.x;
    this->y = other.y;
}

//overloading + operator to sum x of objects and y together and return another object
Point operator+(const Point& point1, const Point& point2) {
    return Point(point1.x + point2.x, point1.y + point2.y);
}


//overloading - operator to subtract x of objects and y's together and return another object
Point operator-(const Point &point1, const Point &point2) {
    return Point(point1.x - point2.x, point1.y - point2.y);
}

//overloading /= operator to divide x and y of the object by a int and return the new point
Point& Point::operator/=(int num) {
    if (num == 0){
        throw invalid_argument("cannot divide the point by 0");
    }
    x /= num;
    y /= num;
    return *this;
}

//overloading = operator for assigning an object to another one
Point& Point::operator=(const Point& other) {
    //checks for self assignment
    if (this == &other){
        return *this;
    }
    this->x = other.x;
    this->y = other.y;
    return *this;
}

bool Point::operator>=(const Point& point2) const {
    //the condition first find distance of each point form (0,0) and compares the distances
    if(sqrt((this->x * this->x) + (this->y * this->y)) >=
    sqrt((point2.x * point2.x) + (point2.y * point2.y))){
        return true;
    }
    return false;
}

//getters and setters
int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    this->x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    this->y = y;
}

