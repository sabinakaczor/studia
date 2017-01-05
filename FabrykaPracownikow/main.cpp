#include <iostream>
#include <vector>

using namespace std;

class Person
{
public:
    vector<int> get_rooms()
    {
        return this->rooms;
    }

    void set_rooms(vector<int> rooms)
    {
        this->rooms = rooms;
    }

private:
    vector<int> rooms;
};

class Cleaner : public Person
{
public:

};

class Receptionist : public Person
{
public:

};

class Boss : public Person
{
public:

};

class Admin : public Person
{
public:

};

class Guest : public Person
{
public:

};

class EmployeeFactory
{
public:
    EmployeeFactory()
    {
        last_free_room = 5;
        basement_keys = 1;
        rooftop_keys = 40;
        boss_room_keys = 20;
        stock_room_keys = 2;
        conference_room_keys = 11;
        laundry_keys = 4;
        cleaner_room_keys = 3;
    }

    Person* createEmployee(string name)
    {
        Person *ret;
        vector<int> keys;
        if (name == "szef") {
            ret = new Boss();
            keys.push_back(boss_room_keys);
            keys.push_back(stock_room_keys);
            keys.push_back(rooftop_keys);
            keys.push_back(basement_keys);
            ret->set_rooms(keys);
        } else if (name == "admin") {
            // stworzyc administratora
            // nadac klucze
            ret = new Admin();
            for (int i=1; i<=40; ++i) {
                if (i!=boss_room_keys)
                    keys.push_back(i);
            }
            ret->set_rooms(keys);
        } else if (name == "sprzataczka") {
            // stworzyc sprzataczke
            // nadac klucze
            ret = new Cleaner();
            keys.push_back(cleaner_room_keys);
            keys.push_back(laundry_keys);
            keys.push_back(conference_room_keys);
            for (int i=5; i<=39; ++i) {
                if (i!=conference_room_keys && i!=boss_room_keys)
                    keys.push_back(i);
            }
            ret->set_rooms(keys);
        } else if (name == "recepcjonistka") {
            // stworzyc recepcjonistke
            // nadac klucze
            ret = new Receptionist();
            keys.push_back(stock_room_keys);
            keys.push_back(conference_room_keys);
            for (int i=5; i<=39; ++i) {
                if (i!=conference_room_keys && i!=boss_room_keys)
                    keys.push_back(i);
            }
            ret->set_rooms(keys);
        } else if (name == "gosc") {
            // stworzyc goscia
            // nadac klucze
            ret = new Guest();
            keys.push_back(get_next_guest_room_key());
            ret->set_rooms(keys);
        }
        return ret;
    }
private:
    int last_free_room;
    int basement_keys;
    int rooftop_keys;
    int boss_room_keys;
    int stock_room_keys;
    int conference_room_keys;
    int laundry_keys;
    int cleaner_room_keys;

    int get_next_guest_room_key()
    {
        while (last_free_room == boss_room_keys ||
               last_free_room == rooftop_keys ||
               last_free_room == conference_room_keys) {
            last_free_room += 1;
        }
        return last_free_room;
    }

    vector<int> get_all_guest_room_keys()
    {
        vector<int> ret;
        int i = 5;
        for (int i=5; i < 40; ++i) {
            if (!(i == boss_room_keys ||
                   i == rooftop_keys ||
                   i == conference_room_keys)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main()
{
    EmployeeFactory *ef = new EmployeeFactory();
    Person *sprzataczka = ef->createEmployee("sprzataczka");
    Person *szef = ef->createEmployee("szef");
    Person *recepcjonistka = ef->createEmployee("recepcjonistka");
    vector<int> spr = sprzataczka->get_rooms();
    vector<int> sz = szef->get_rooms();
    vector<int> rec = recepcjonistka->get_rooms();
    cout << "Sprzątaczka: ";
    for(int i=0; i<spr.size(); ++i)
        cout << spr[i] << " ";
    cout << "\nSzef: ";
    for(int i=0; i<sz.size(); ++i)
        cout << sz[i] << " ";
    cout << "\nRecepcjonistka: ";
    for(int i=0; i<rec.size(); ++i)
        cout << rec[i] << " ";
    return 0;
}
