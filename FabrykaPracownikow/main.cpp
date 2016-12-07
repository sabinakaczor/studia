#include <iostream>
#include <vector>

using namespace std;

//klasy z pracownikami
class Person
{
public:
    virtual vector<int> get_rooms() = 0;
};

class Cleaner : public Person
{
public:
    vector<int> get_rooms() {
        return this->rooms;
    }
};

class Receptionist : public Person
{
public:
    vector<int> get_rooms() {
        return this->rooms;
    }
};

class Boss : public Person
{
public:
    vector<int> get_rooms() {
        return this->rooms;
    }
};

class Admin : public Person
{
public:
    vector<int> get_rooms() {
        return this->rooms;
    }
};

class Guest : public Person
{
public:
    vector<int> get_rooms() {
        return this->rooms;
    }
};

//fabryki pracowników
class EmployeeFactory
{
public:
    virtual Person* createEmployee() = 0;
protected:
    virtual vector<int> set_rooms() = 0;
};

class CleanerFactory : public EmployeeFactory
{
public:
    Person* createEmployee() {
        return new Cleaner();
    }
private:
    vector<int> set_rooms() {
        vector<int> rooms;
        for(int i=3; i<=39; ++i) {
            if (i != 20)
                rooms.push_back(i);
        }
        return rooms;
    }
};

class ReceptionistFactory : public EmployeeFactory
{
public:
    Person* createEmployee() {
        return new Receptionist();
    }
private:
    vector<int> set_rooms() {
        vector<int> rooms;
        for(int i=2; i<=39; ++i) {
            if (i != 3 && i != 4 && i != 20)
                rooms.push_back(i);
        }
        return rooms;
    }
};

class BossFactory : public EmployeeFactory
{
public:
    Person* createEmployee() {
        return new Boss();
    }
private:
    vector<int> set_rooms() {
        vector<int> rooms;
        rooms.push_back(1);
        rooms.push_back(2);
        rooms.push_back(20);
        rooms.push_back(40);
        return rooms;
    }
};

class AdminFactory : public EmployeeFactory
{
public:
    Person* createEmployee() {
        return new Admin();
    }
private:
    vector<int> set_rooms() {
        vector<int> rooms;
        for(int i=1; i<=40; ++i) {
            if (i != 20)
                rooms.push_back(i);
        }
        return rooms;
    }
};

class GuestFactory : public EmployeeFactory
{
public:
    Person* createEmployee() {
        return new Guest();
    }
private:
    vector<int> set_rooms() {
        vector<int> rooms;
        rooms.push_back(this->room_no);
        return rooms;
    }
};

int main()
{
    return 0;
}
