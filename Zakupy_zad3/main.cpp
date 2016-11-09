#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

class Country{
public:
    Country(string name, string abbr)  {
        this->name = name;
        this->abbr = abbr;
    }
    string name;
    string abbr;
};

class Currency{
public:
    string currency;
    Currency(string currency) {
        this->currency=currency;
    }
};

class Item{
public:
    string name;
    Item(string name) {
        this->name = name;
    }
};

class Customer : public Country{
public:
    string firstname;
    string lastname;
    string country;
    Customer(string name, string lastname, string country) : Country(name,abbr) {
        this->name = firstname;
        this->lastname = lastname;
        this->country = name;
    }
};

class Order{
public:
    string fname;
    Order(string fname) {
        this->fname = fname;
    }
};

int main()
{
    fstream f;
    string line;
    vector<string> lines;
    f.open("order.txt",ios::in);
    if(f.is_open()) {
        f >> line;
        while(!f.eof()) {
            lines.push_back(line);
            f >> line;
        }
        f.close();
    }else {
        cout << "b³¹d otwarcia order.txt";
    }




    return 0;
}
