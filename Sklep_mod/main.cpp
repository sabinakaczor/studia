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
    string get_currency() { return currency; }

    float convert_currency(float value) {
        return value / conversion_rate;
    }

    float get_gross_value(float cost) {
        return cost * (1 + tax / 100);
    }

private:
    string currency;
    float conversion_rate;
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
        float real_cost = this->country->get_currency()->convert_currency
                        (this->country->get_currency()->get_gross_value(cost));
        string currency_name = this->country->get_currency()->get_currency();
        cout << firstname << " " << lastname << " zapłacił przez internet kwotę " << real_cost
                            << " " << currency_name << "." << endl;
    }

    bool identify(string lastname, string name) {
        return (name==this->firstname && lastname==this->lastname);
    }
private:
    string firstname;
    string lastname;
    Country *country;
};

class OrderPosition {
public:
    OrderPosition(Item *item, int price, int number) {
        this->item=item;
        this->price=price;
        this->number=number;
    }
    float get_cost() { return price * number; }

private:
    Item *item;
    int price;
    int number;
};

class Order{
public:

    Order(int id, vector<OrderPosition> ops, Customer *customer) {
        this->id=id;
        this->customer=customer;
        this->cost = count_cost(ops);
    }

    void start_payment() { customer->payment(cost); }

private:
    int id;
    int number;
    int price;
    Item *item;
    Customer *customer;
    float cost;

    float count_cost(vector<OrderPosition> ops) {
        float cost = 0;
        for (int i=0; i<ops.size(); ++i) {
            cost += ops[i].get_cost();
        }
        return cost;
    }
};


int get_customer_index(string ln, string n, vector<Customer> customers) {
    for (int i=0; i < customers.size(); ++i) {
        if(customers[i].identify(ln,n)) {
            return i;
        }
    }
    return -1;
}

int get_product_index(string product, vector<Item> items) {
    for(int i=0; i < items.size(); ++i) {
        if(items[i].identify(product)) {
            return i;
        }
    }
    return -1;
}

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

    vector<OrderPosition> ops;
    string names[2], lastnames[2], products[2];
    int numbers[2],ids[2],prices[2];

    fstream f;
    string w;
    int n;
    f.open("order.txt",ios::in);
    if (f.is_open()) {
        f >> lastnames[0];
        f >> names[0];
        f >> ids[0];
        f >> numbers[0];
        f >> products[0];
        f >> prices[0];

        int i = get_customer_index(lastnames[0],names[0],customers);
        int j = get_product_index(products[0],items);

        ops.push_back(OrderPosition(&items[j],numbers[0],prices[0]));

        while(!f.eof()) {

            f >> lastnames[1];
            f >> names[1];
            f >> ids[1];
            f >> numbers[1];
            f >> products[1];
            f >> prices[1];

            if (ids[1]>ids[0]) {
                Order *order = new Order(ids[0],ops,&customers[get_customer_index(lastnames[0],names[0],customers)]);
                order->start_payment();
                ops.erase(ops.begin(),ops.end());
            }
            if(!f.eof())
                ops.push_back(OrderPosition(&items[get_product_index(products[1],items)],numbers[1],prices[1]));

            lastnames[0]=lastnames[1];
            names[0]=names[1];
            ids[0]=ids[1];
            numbers[0]=numbers[1];
            products[0]=products[1];
            prices[0]=prices[1];

        }
        Order *order = new Order(ids[0],ops,&customers[get_customer_index(lastnames[0],names[0],customers)]);
        order->start_payment();

        f.close();
    }else {
        cout << "błąd otwarcia order.txt";
    }


    return 0;
}

