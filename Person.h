#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include "Address.h"

using namespace std;

#ifndef PERSON_H
#define PERSON_H


//prototype of class Person

class Person {
public:
    Person();
    Person(const string& name,const string& id,const Address& address);
    Person(const Person& person);
    const string& getName() const;
    void setName(const string& name);
    const string& getId() const;
    void setId(const string& id);
    const Address& getAddress() const;
    void setAddress(const Address& address);
    friend ostream& operator << (ostream& strm, const Person& obj);
    friend istream& operator >> (istream& strm, Person& obj);
    Person& operator = (const Person& other);
    bool validate(const string& id);


private:
    string name;
    string id;
    Address address;
};


#endif