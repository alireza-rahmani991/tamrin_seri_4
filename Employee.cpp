#include "Employee.h"



//employee class functions bodies


//no argument constructor
Employee::Employee(){
    this->address = Address();
    this->id = "";
    this->name = "";
    this->hourWork = 0;
    this->salaryPerHour = 0;
    this->workDone = 0;
    this->workToDo = 0;
}

//constructor to give value to all the variables
Employee::Employee(const string& name,const string& id, const Address& address, int hourWork, int salaryPerHour
        , int workToDo, int workDone){
    if(!validate(id)){
        cout<<"invalid id";
        exit(0);
    }
    this->name = name;
    this->id = id;
    this->address = address;
    this->hourWork = hourWork;
    this->salaryPerHour = salaryPerHour;
    this->workToDo = workToDo;
    this->workDone = workDone;
}

//copy constructor
Employee::Employee(const Employee& employee) {
    this->name = employee.name;
    this->id = employee.id;
    this->address = employee.address;
    this->hourWork = employee.hourWork;
    this->salaryPerHour = employee.salaryPerHour;
    this->workToDo = employee.workToDo;
    this->workDone = employee.workDone;

}

int Employee::getHourWork() const {
    return hourWork;
}

void Employee::setHourWork(int hourWork) {
    Employee::hourWork = hourWork;
}

int Employee::getSalaryPerHour() const {
    return salaryPerHour;
}

void Employee::setSalaryPerHour(int salaryPerHour) {
    Employee::salaryPerHour = salaryPerHour;
}

int Employee::getWorkToDo() const {
    return workToDo;
}

void Employee::setWorkToDo(int workToDo) {
    Employee::workToDo = workToDo;
}

int Employee::getWorkDone() const {
    return workDone;
}

void Employee::setWorkDone(int workDone) {
    Employee::workDone = workDone;
}

//overloading << operator so it outputs all the data
ostream& operator<<(ostream& strm, const Employee& employee) {
    strm << "name: " << employee.name << " id: " << employee.id << " address: " << employee.address << " hourWork: "
         << employee.hourWork << " salaryPerHour: " << employee.salaryPerHour << " workToDo: " << employee.workToDo
         << " workDone: " << employee.workDone;
    return strm;
}


//overloading >> operator to get data from user and set it to the object
istream &operator>>(istream& strm, Employee& obj) {
    strm>>obj.name>>obj.id>>obj.address>>obj.hourWork>>obj.salaryPerHour>>obj.workToDo>>obj.workDone;
    return strm;
}

//overloading assignment operator
Employee& Employee::operator=(const Employee &other){
    if(this == &other){
        return *this;
    }
    this->name = other.name;
    this->id = other.id;
    this->address = other.address;
    this->hourWork = other.hourWork;
    this->salaryPerHour = other.salaryPerHour;
    this->workToDo = other.workToDo;
    this->workDone = other.workDone;
    return *this;
}

//use regex to check if id is valid
bool Employee::validate(const string& id) {
    regex pattern(R"(^(8[4-9]|9[0-9])\*[^0-9]{1,2}([0-3]|[7-9]){5}$)");
    //uses regex pattern to validate id
    if(regex_match(id, pattern)){
        return true;
    }
    return false;
}

double Employee::calculateSalary() {
    if(workToDo == 0){
        return 0;
    }
    double salary =  hourWork * salaryPerHour;
    double percentNotDone = ((workToDo - workDone)* 100) / (double)workToDo  ;
    salary -= (percentNotDone* salary) / 100;
    return salary;
}

double Employee::efficiency() {
    if(workToDo == 0 || hourWork == 0){
        return 0;
    }
    double percentDone = (workDone / (double)workToDo) * 100;
    double efficiency = percentDone / hourWork;
    return efficiency;
}
