#include <iostream>

using namespace std;

class Rozliczanie
{
public:
    virtual void rozlicz(string sposob, float przychod, int dzieci, float koszty) = 0;
    virtual void oblicz_podatek() = 0;
protected:
    float stawka_podatku;
    float przychod;
};

class Osoba_Fizyczna : public Rozliczanie
{
public:
    void rozlicz() {
        cout << "Rozliczanie jako: osoba fizyczna";
        if (this->przychod <= 100000) {
            this->stawka_podatku = 15;
        } else {
            this->stawka_podatku = 30;
        }

    }
};

class Osoba_Prawna : public Rozliczanie
{
public:
     void rozlicz() {
            cout << "Rozliczanie jako: osoba prawna";
            this->stawka_podatku = 20;
    }
};

class Malzenstwo : public Rozliczanie
{
public:
     void rozlicz() {
        cout << "Rozliczanie jako: ma³¿eñstwo";
        if (this->przychod <= 100000) {
            this->stawka_podatku = 15;
        } else {
            this->stawka_podatku = 30;
        }
    }

};




class Podatnik
{
public:
    Podatnik(string sposob, float przychod, int dzieci, float koszty) {
        if (sposob=="osoba fizyczna") {
            rozliczanie = new Osoba_Fizyczna(sposob, przychod, dzieci, koszty);
        }
        else if (sposob=="osoba prawna") {
            rozliczanie = new Osoba_Prawna(sposob, przychod, dzieci, koszty);
        }
        else if (sposob=="malzenstwo") {
            rozliczanie = new Malzenstwo(sposob, przychod, dzieci, koszty);
        }
        this->przychod = przychod;
    }
private:
    Rozliczanie *rozliczanie;
    float przychod;
};

int main()
{
    return 0;
}
