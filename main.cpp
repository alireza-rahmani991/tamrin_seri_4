#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Address.h"
#include "Person.h"
#include "Employee.h"

int main(){
    //tests for addres class
    Address addr1;
    Address addr2("iran", "tehran", "valiAsr");
    cout<<"no argumant constructor: "<<addr1;
    cout<<"three argument constructor: "<<addr2;
    cout<<"enter address in one line for testing >>"<<endl;
    //cin>>addr1;
    cout<<addr1;
    addr2.setCountry("england");
    cout<<"using getters and setters: "<<addr2.getCountry()<<endl;


    //tests for person class(using invalid id in constructor will exit the application so i dont test it)
    Person person1;
    //in constructor id will be checked and if its not valid error message will be printed and program will exit.
    Person person2("ali", "89ac11111", addr1);
    cout<<"using no argument constructor: "<<person1;
    cout<<"using the main constructor: "<<person2;
    cout<<"enter values for person:"<<endl;
    //cin>>person1;
    cout<<person1;
    person1.setId("80a1ac");
    cout<<"using getters and setters: "<<person1.getId();
    Person person3;
    person3 = person2;
    cout<<"assingment operator: "<<person3;



    //tests for employee class
    Employee employee1;
    //if the id is invalid error message will be printed and it will exit the program completly
    Employee employee2("ali", "89*a11111", addr1, 50, 12, 25, 12);
    cout<<"using no argument constructor: "<<employee1;
    cout<<"using the main constructor: "<<employee2;
    Employee employee3 = employee2;
    cout<<"using copy constructor"<<employee3;
    cout<<"enter data to test >> operator:"<<endl;
    //cin>>employee1;
    cout<<employee1;
    Employee employee4;
    employee4 = employee3;
    cout<<"= operator test: "<<employee4;
    cout<<"salary of the employee got by input is: "<<employee1.calculateSalary()<<" and his efficiency is: "<<employee1.efficiency()<<endl;



    //point class test
    Point point1;
    Point point2(-1, 3);
    Point point3 = point2;
    cout<<"using no argumant constructor: X: "<<point1.getX()<<" Y: "<<point1.getY()<<endl;
    cout<<"using 2 argumant constructor: X: "<<point2.getX()<<" Y: "<<point2.getY()<<endl;
    cout<<"using copy constructor : X: "<<point3.getX()<<" Y: "<<point3.getY()<<endl;
    point1.setX(6);
    point1.setY(-7);
    cout<<"using copy constructor : X: "<<point1.getX()<<" Y: "<<point1.getY()<<endl;
    if(point1 >= point2){
        cout<<"point 1 bigger"<<endl;
    }
    point1 /= 2;
    cout<<"using /=2: X: "<<point1.getX()<<" Y: "<<point1.getY()<<endl;
    Point point4 = point1 + point2;
    Point point5 = point4 - point1;
    cout<<"using + operator: X: "<<point4.getX()<<" Y: "<<point4.getY()<<endl;
    cout<<"using - operator: X: "<<point5.getX()<<" Y: "<<point5.getY()<<endl<<endl;

    //tests for rectangle class
    Point rectPoint1(2, 3);
    Point rectPoint2(8, 15);
    Point rectPoint3(1 , 1);
    Rectangle rectangle1(rectPoint1, 10,2 );
    Rectangle rectangle2(rectPoint2, 3, 2);
    cout<<"using main constructor: "<<"start point X: "<<rectangle1.getStartPoint().getX()
    <<" start point Y: "<<rectangle1.getStartPoint().getY()<<" width: "<<rectangle1.getWidth()
    <<" height: "<<rectangle1.getHeight()<<endl;
    rectangle1 += rectangle2;
    cout<<"using +=(failed): "<<"start point X: "<<rectangle1.getStartPoint().getX()
        <<" start point Y: "<<rectangle1.getStartPoint().getY()<<" width: "<<rectangle1.getWidth()
        <<" height: "<<rectangle1.getHeight()<<endl;
    Rectangle rectangle3(rectPoint1, 15, 1);
    rectangle1 += rectangle3;
    cout<<"using +=: "<<"start point X: "<<rectangle1.getStartPoint().getX()
        <<" start point Y: "<<rectangle1.getStartPoint().getY()<<" width: "<<rectangle1.getWidth()
        <<" height: "<<rectangle1.getHeight()<<endl;
    Rectangle rectangle4 (rectPoint1, 6, 3);
    rectangle1 -= rectangle4;
    cout<<"using -=: "<<"start point X: "<<rectangle1.getStartPoint().getX()
        <<" start point Y: "<<rectangle1.getStartPoint().getY()<<" width: "<<rectangle1.getWidth()
        <<" height: "<<rectangle1.getHeight()<<endl;

    Rectangle rectangle5 = rectangle1 / rectangle2;
    cout<<"using / : "<<"start point X: "<<rectangle5.getStartPoint().getX()
        <<" start point Y: "<<rectangle5.getStartPoint().getY()<<" width: "<<rectangle5.getWidth()
        <<" height: "<<rectangle5.getHeight();

    Rectangle rectangleCol1(rectPoint1, 5 , 3);
    Rectangle rectangleCol2(rectPoint3, 6, 4);
    if(rectangleCol1.collisionDetection(rectangleCol2)){
        cout<<endl<<"the rectangleCol1 and rectangleCol2 have collision";
    }
    return 0;
}