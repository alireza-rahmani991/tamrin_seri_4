#include "Rectangle.h"


//no argument constructor to give default value to everything
Rectangle::Rectangle() {
    startPoint = Point();
    width = 0;
    height = 0;
}

//constructor to get and set each value
Rectangle::Rectangle(const Point &startPoint, int width, int height) {
    this->startPoint = startPoint;
    this->width = width;
    this->height = height;
}

//copy constructor
Rectangle::Rectangle(const Rectangle& other){
    this->startPoint = other.startPoint;
    this->height = other.height;
    this->width = other.width;
}

//getters and setters
const Point &Rectangle::getStartPoint() const {
    return startPoint;
}

void Rectangle::setStartPoint(const Point &startPoint) {
    Rectangle::startPoint = startPoint;
}

int Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(int width) {
    Rectangle::width = width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(int height) {
    Rectangle::height = height;
}

//overloading += operator. result is a rectangle with the biggest height and width
Rectangle& Rectangle::operator+=(const Rectangle& other) {
    if(this->startPoint.getX() != other.startPoint.getX() || this->startPoint.getY() != other.startPoint.getY()){
        cout<<"start points arent same"<<endl;
        return *this;
    }
    int maxHeight, maxWidth;
    if(this->height < other.height){
    this->height = other.height;
    }
    if(this->width < other.width){
        this->width = other.width;
    }
    return *this;
}

//overloading -= operator. result is a rectangle with the smallest height and width
Rectangle& Rectangle::operator-=(const Rectangle& other) {
    if(this->startPoint.getX() != other.startPoint.getX() || this->startPoint.getY() != other.startPoint.getY()){
        cout<<"start points arent same"<<endl;
        return *this;
    }
    int maxHeight, maxWidth;
    if(this->height > other.height){
        this->height = other.height;
    }
    if(this->width > other.width){
        this->width = other.width;
    }
    return *this;
}

//overloading operator / so when two rectangles are divided the start point will be in the middle of
//start points and the height and width of the resualt will be resualt of divide of their heights and widths.
Rectangle operator/(const Rectangle &rectangle1, const Rectangle &rectangle2) {
    int newX = (rectangle1.startPoint.getX() + rectangle2.startPoint.getX()) / 2;
    int newY = (rectangle1.startPoint.getY() + rectangle2.startPoint.getY()) / 2;
    Point newPoint(newX, newY);
    int newWidth = rectangle1.width / rectangle2.width;
    int newHeight = rectangle1.height / rectangle2.height;
    return Rectangle (newPoint, newWidth, newHeight);

}

//checks collision of two rectangles by calculating each point of each rectangle and then
//checking if the edges are in places that they collide.
bool Rectangle::collisionDetection(const Rectangle &other) const {
    int left1 = this->startPoint.getX();
    int right1 = this->startPoint.getX() + width;
    int top1 = this->startPoint.getY();
    int bottom1 = this->startPoint.getY() + height;


    int left2 = other.startPoint.getX();
    int right2 = other.startPoint.getX() + other.width;
    int top2 = other.startPoint.getY();
    int bottom2 = other.startPoint.getY() + other.height;
    bool overlapX = (left1 < right2) && (right1 > left2);

    bool overlapY = (top1 < bottom2) && (bottom1 > top2);

    return overlapX && overlapY;
}

