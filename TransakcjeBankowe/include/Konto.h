#ifndef KONTO_H
#define KONTO_H


class Konto
{
    public:
        Konto();
        ~Konto();
        void wyswietl_stan_konta();

    protected:

    private:
        void wczytaj_konta();
};

#endif // KONTO_H
