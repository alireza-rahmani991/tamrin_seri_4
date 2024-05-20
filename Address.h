#include <string>
#include <iostream>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H

//prototype of class address
class Address {
public:
    Address();
    Address(const string& country,const string& city,const string& street);
    const string& getCountry() const;
    void setCountry(const string &country);
    const string& getCity() const;
    void setCity(const string &city);
    const string& getStreet() const;
    void setStreet(const string &street);
    friend ostream& operator << (ostream& strm, const Address& obj);
    friend istream& operator >> (istream& strm, Address& obj);

private:
    string country;
    string city;
    string street;
};


#endif
