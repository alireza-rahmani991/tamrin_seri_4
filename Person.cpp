#include "Person.h"

//Person class functions bodies



//no argument constructor
Person::Person() {
    this->name = "";
    this->id = "";
    this->address = Address();
}

// 3 argument constructor to create an object with given info
Person::Person(const string& name,const string& id,const Address& address) {
    if(!validate(id)){
        cout<<"invalid id"<<endl;
        exit(0);
    }
    this->name = name;
    this->id = id;
    this->address = address;
}

//copy constructor for person
Person::Person(const Person& person) {
    this->address = person.address;
    this->id = person.id;
    this->name = person.name;
}

//getters and setters for the class
const string& Person::getName() const {
    return name;
}

void Person::setName(const string& name) {
    this->name = name;
}

const string& Person::getId() const {
    return id;
}

void Person::setId(const string& id) {
    if(validate(id)){
        this->id = id;
    }
    else {
        cout<<"invalid id"<<endl;
    }
}

const Address& Person::getAddress() const {
    return address;
}

void Person::setAddress(const Address& address) {
    this->address = address;
}


//overloading << operator so it outputs all the data
ostream& operator<<(ostream& strm, const Person& obj) {

    strm<<"name: "<<obj.name<<"\t id: "<<obj.id<<"\t address: "<<obj.address<<endl;

    return strm;
}

//overloading >> operator to get data from user and set it to the object
istream& operator >>(istream& strm, Person& obj) {
    strm>>obj.name>>obj.id>>obj.address;
    while(obj.validate(obj.id)){
        cout<<"invalid id please enter id again"<<endl;
        strm>>obj.id;
    }
    return strm;
}

//overloading assignment operator
Person& Person::operator=(const Person& other){
    if(this == &other){
        return *this;
    }
    this->name= other.name;
    this->id = other.id;
    this->address = other.address;
    return *this;
}

//using regex to validate id
bool Person::validate(const string& id) {
    regex pattern(R"(^(8[4-9]|9[0-9])[^0-9]{1,3}([0-3]|[7-9]){5}$)");

    // Check if the string matches the regex pattern
    if (std::regex_match(id, pattern)) {
        return true;
    }
    return false;
}

