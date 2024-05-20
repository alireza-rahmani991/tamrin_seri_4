#include "Address.h"

//address class functions bodies

//constructors for the class
Address::Address() {
    country = "";
    city = "";
    street = "";
}

Address::Address(const string& country,const string& city,const string& street) {
    this->country = country;
    this->city = city;
    this->street = street;
}


//getters and setters for the class
const string& Address::getCountry() const {
    return country;
}

void Address::setCountry(const string &country) {
    this->country = country;
}

const string& Address::getCity() const {
    return city;
}

void Address::setCity(const string &city) {
    this->city = city;
}

const string& Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    this->street = street;
}


//overloading << to output objects data
ostream& operator<<(ostream& strm, const Address& obj) {

    strm<<"country: "<<obj.country<<"\t city: "<<obj.city<<"\t street: "<<obj.street<<endl;

    return strm;
}

//overloading >> operator to get data from user and set it to the object
istream& operator >>(istream& strm, Address& obj) {
    strm>>obj.country>>obj.city>>obj.street;
    return strm;
}

