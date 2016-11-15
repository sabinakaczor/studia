#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Currency{
public:
    Currency(string currency, float tax, float conversion_rate) {
        this->currency=currency;
        this->conversion_rate=conversion_rate;
        this->tax = tax;
    }
    //getter
    string get_currency() { return currency; }

     // getter (inline)
    float get_tax() { return tax; }

    float convert_currency(float value) {
        return value / conversion_rate;
    }

    float get_gross_value(float cost) {
        return cost * (1 + tax / 100);
    }

private:
    string currency;
    float conversion_rate; //GBP - 6
    float tax;
};

class Country{
public:
    Country(string name, string abbr, Currency *currency)  {
        this->name = name;
        this->abbr = abbr;
        this->currency=currency;
    }

    Currency* get_currency() { return currency; }

private:
    string name;
    string abbr;
    Currency *currency;
};

class Item{
public:
    Item(string name) {
        this->name = name;
    }
    bool identify(string product) {
        return (product==this->name);
    }
private:
    string name;
};

class Customer{
public:
    Customer(string lastname, string firstname, Country *country){
        this->firstname = firstname;
        this->lastname = lastname;
        this->country = country;
    }
    void payment(float cost) {
        // country ma miec currency, nie odwrotnie
        // tax w currency, nie w country
        // w currency również pobranie kwoty brutto
        // XY zapłacił przez internet kwotę ... <waluta>
        float real_cost = this->country->get_currency()->convert_currency
                        (this->country->get_currency()->get_gross_value(cost));

        string currency_name = this->country->get_currency()->get_currency();
        // wyświetlic
        cout << firstname << " " << lastname << " zapłacił przez internet kwotę " << real_cost << " " << currency_name << "." << endl;
    }

    bool identify(string lastname, string name) {
        return (name==this->firstname && lastname==this->lastname);
    }
private:
    string firstname;
    string lastname;
    Country *country;
};

class Order{
public:

    Order( int id, int number, int price, Item *item, Customer *customer) {
        this->id=id;
        this->number=number;
        this->price=price;
        this->item=item;
        this->customer=customer;
        this->cost=price*number;
    }

    void start_payment() { customer->payment(cost); }

private:
    int id;
    int number;
    int price;
    Item *item;
    Customer *customer;
    float cost;
};

int main()
{
    vector<Currency> currencies;
    currencies.push_back(Currency("PLN", 20, 1));
    currencies.push_back(Currency("GBP", 40, 6));

    vector<Country> countries;
    countries.push_back(Country("Polska", "PL", &currencies[0]));
    countries.push_back(Country("Wielka Brytania", "GB", &currencies[1]));

    vector<Item> items;
    items.push_back(Item("stolik"));
    items.push_back(Item("szafa"));
    items.push_back(Item("lustro"));

    vector<Customer> customers;
    customers.push_back(Customer("Tokar", "Marcin", &countries[0]));
    customers.push_back(Customer("Omiotek", "Piotr", &countries[0]));
    customers.push_back(Customer("Smith", "John", &countries[1]));

//    Order *o = new Order();
  //  vector<Order> tab;
    //o->id = 43;
    //o->lastname = "fhf";


    fstream f;
    string ln, n, product;
    int id, no, price;
    f.open("order.txt",ios::in);
    if (f.is_open()) {
        f >> ln;
        while(!f.eof()) {
            f >> n;
            f >> id;
            f >> no;
            f >> product;
            f >> price;

            for (int i=0; i < customers.size(); ++i) {
                if(customers[i].identify(ln,n)) {
                    for(int j=0; j < items.size(); ++j) {
                        if(items[j].identify(product)) {
                            Order *order = new Order(id,no,price,&items[j],&customers[i]);
                            order->start_payment();
                            goto end;
                        }
                    }
                }
            }
            end:
            f >> ln;
        }
        f.close();
    }else {
        cout << "błąd otwarcia order.txt";
    }

    //o->lastname = "gj";

    //cout << order[0] << endl;




    return 0;
}
