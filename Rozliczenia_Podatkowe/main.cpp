#include <iostream>

using namespace std;

class Podatnik
{
public:
    Podatnik(float przychod, int l_dzieci, float czynsz) {
        this->przychod = przychod;
        this->l_dzieci = l_dzieci;
        this->czynsz = czynsz;
    }
    float get_przychod() const {
        return this->przychod;
    }
    float get_czynsz() const {
        return this->czynsz;
    }
    float get_l_dzieci() const {
        return this->l_dzieci;
    }

private:
    float przychod;
    unsigned int l_dzieci;
    float czynsz;
};

class Rozliczanie
{
public:
    virtual ~Rozliczanie() {}
    virtual float oblicz_podatek(Podatnik*) = 0;

protected:
    float stawka_podatku;
    float koszt_przychodu;
    float dochod;
};

class Osoba_Fizyczna : public Rozliczanie
{
public:
    float oblicz_podatek(Podatnik *p) {
        if (p->get_przychod() <= 100000) {
            this->stawka_podatku = 0.15;
        } else {
            this->stawka_podatku = 0.30;
        }
        this->koszt_przychodu = p->get_czynsz();
        if (this->koszt_przychodu > 10000) {
            this->koszt_przychodu = 10000;
        }
        this->dochod = p->get_przychod() - this->koszt_przychodu;
        return this->dochod * this->stawka_podatku;
    }
};

class Osoba_Prawna : public Rozliczanie
{
public:
    float oblicz_podatek(Podatnik *p) {
        this->stawka_podatku = 0.20;
        this->koszt_przychodu = p->get_czynsz();
        if (this->koszt_przychodu > 15000) {
            this->koszt_przychodu = 15000;
        }
        this->dochod = p->get_przychod() - this->koszt_przychodu;
        return this->dochod * this->stawka_podatku;
    }
};

class Malzenstwo : public Rozliczanie
{
public:
    float oblicz_podatek(Podatnik *p) {
        if (p->get_przychod() <= 200000) {
            this->stawka_podatku = 0.15;
        } else {
            this->stawka_podatku = 0.30;
        }
        this->koszt_przychodu = p->get_czynsz();
        this->koszt_przychodu += p->get_l_dzieci() * 500;
        if (this->koszt_przychodu > 20000) {
            this->koszt_przychodu = 20000;
        }
        this->dochod = p->get_przychod() - this->koszt_przychodu;
        return this->dochod * this->stawka_podatku;
    }

};




class PodatekDochodowy
{
public:
    PodatekDochodowy(string sposob, Podatnik *p) {
        this->sposob = sposob;
        this->podatnik = p;
    }
    float get_podatek() {
        return this->rozlicz();
    }
private:
    string sposob;
    Podatnik *podatnik;
    float rozlicz() {
        if (this->sposob=="osoba fizyczna") {
            Osoba_Fizyczna *rozliczanie = new Osoba_Fizyczna();
            cout << "Rozliczanie jako: osoba fizyczna: ";
            return rozliczanie->oblicz_podatek(this->podatnik);
        }
        else if (this->sposob=="osoba prawna") {
            Osoba_Prawna *rozliczanie = new Osoba_Prawna();
            cout << "Rozliczanie jako: osoba prawna: ";
            return rozliczanie->oblicz_podatek(this->podatnik);
        }
        else if (this->sposob=="malzenstwo") {
            Malzenstwo *rozliczanie = new Malzenstwo();
            cout << "Rozliczanie jako: malzenstwo: ";
            return rozliczanie->oblicz_podatek(this->podatnik);
        }
    }
};

int main()
{
    Podatnik *p = new Podatnik(300000,2,15000);
    PodatekDochodowy *fiz = new PodatekDochodowy("osoba fizyczna", p);
    PodatekDochodowy *pr = new PodatekDochodowy("osoba prawna", p);
    PodatekDochodowy *mal = new PodatekDochodowy("malzenstwo", p);
    cout << fiz->get_podatek() << endl;
    cout << pr->get_podatek() << endl;
    cout << mal->get_podatek() << endl;
    return 0;
}
