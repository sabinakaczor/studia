#include <iostream>

using namespace std;


class Validator
{
public:
    virtual bool validate() = 0;
    /*bool validate(string str) {
        if() {
            return true;
        }
        return false;
    }*/

private:
};

class ValidatorTXT
{

};

class ValidatorALFA
{

};

class ValidatorNUM
{

};

class ValidatorPOINT
{

};

class ValidatorBIG
{

};

class ValidatorEVEN
{

};

int main()
{

    return 0;
}
