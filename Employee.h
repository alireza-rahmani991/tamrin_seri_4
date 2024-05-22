#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include "Address.h"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


//prototype of employee class

class Employee {
public:
    string name;
    string id;
    Address address;
    Employee();
    Employee(const string& name,const string& id, const Address& address, int hourWork, int salaryPerHour
            , int workToDo, int workDone);
    Employee(const Employee& employee);
    int getHourWork() const;
    void setHourWork(int hourWork);
    int getSalaryPerHour() const;
    void setSalaryPerHour(int salaryPerHour);
    int getWorkToDo() const;
    void setWorkToDo(int workToDo);
    int getWorkDone() const;
    void setWorkDone(int workDone);
    friend ostream& operator<<(ostream& strm, const Employee& employee);
    friend istream& operator >> (istream& strm, Employee& obj);
    Employee& operator = (const Employee& other);
    bool validate(const string& id);
    double calculateSalary();
    double efficiency();
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;

};





#endif