#include <iostream>
#include <string>

using namespace std;

class CCzlowiek {
    protected:
        string Imie;
    public:
        CCzlowiek(string Imie) {
            this->Imie = Imie;
        }
        virtual void obowiazkiWDomu() = 0;
        virtual void obowiazkiPozaDomem() {
            cout << "brak obowiązków";
        }
};

class CNiemowle : public CCzlowiek {
    public:
        CNiemowle(string Imie):CCzlowiek(Imie) {}
        void obowiazkiWDomu() {
            cout << "grzecznie spać";
        }
};

class CNastolatek : public CCzlowiek {
    public:
    CNastolatek(string Imie):CCzlowiek(Imie) {}
        void obowiazkiWDomu() {
            cout << "pomagać rodzicom";
        }
        void obowiazkiPozaDomem() {
            cout << "chodzić do szkoły";
        }
};

class CEmeryt : public CCzlowiek {
    public:
    CEmeryt(string Imie):CCzlowiek(Imie) {}
        void obowiazkiWDomu() {
            cout << "być zdrowym";
        }
};

int main()
{
    int N;
    cout << "Podaj dodatnią liczbę całkowitą podzielną przez 3: ";
    cin >> N;
    CCzlowiek** tab = new CCzlowiek*[N];
    for(int i = 0; i < N; ++i) {

        if ((i+1) <= N/3) {
            tab[i] = new CNiemowle("Jaś");
        } else if ((i+1) <= 2*N/3) {
            tab[i] = new CNastolatek("Janek");
        } else {
            tab[i] = new CEmeryt("Jan");
        }
    }

    cout << "\nObowiązki:\n";

    for (int i = 0; i < N; ++i) {

        tab[i]->obowiazkiWDomu();
        cout << "\n";

    }

    return 0;
}
