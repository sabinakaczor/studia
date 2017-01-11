#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

class Obserwator
{
public:
    virtual void update() = 0;
};

class Obserwowany
{
public:
    void dodaj(Obserwator *o) {
        obserwatorzy.push_back(o);
    }
    void usun(Obserwator *o) {
        for(int i=0; i<obserwatorzy.size(); ++i) {
            if (obserwatorzy[i] == o)
                obserwatorzy.erase(obserwatorzy.begin()+i);
        }
    }
    void powiadom() {
        for(int i=0; i<obserwatorzy.size(); ++i)
            obserwatorzy[i]->update(info);
    }
private:
    vector<Obserwator *> obserwatorzy;
};

class ObserwatorKont : public Obserwator
{
public:
    void update(map<string, string> info) {
        fstream file;
        file.open("account_history.txt", ios::out);
        if(file.is_open()) {
            file << info["id"] << " " << info["data"] << " " << info["czas"] << " " << info["nowa wartosc"];
        } else {
            cout << "Nie uda³o siê otworzyæ do zapisu pliku \"account_history,txt\"";
        }
    }
private:
    //Konto *konto;
};

class ObserwatorTransakcji : public Obserwator
{
public:
    void update() {

    }
};

class Konto
{
public:
    Konto(string numer, float stan) {
        this->numer = numer;
        this->stan = stan;
    }
private:
    string numer;
    float stan;
};

class Transakcja
{
public:
    Transakcja(Konto *nadawca, Konto *odbiorca, float kwota) {
        this->nadawca = nadawca;
        this->odbiorca = odbiorca;
        this->kwota = kwota;
    }
private:
    Konto *nadawca;
    Konto *odbiorca;
    float kwota;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
