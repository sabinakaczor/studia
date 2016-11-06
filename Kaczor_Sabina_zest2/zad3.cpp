#include <map>
#include <iostream>
#include <string>

using namespace std;

int getDays(string name, map <string, int> months) {

    string nameCsUns;
    nameCsUns += toupper(name[0]);
    int l = name.size();
    for (int i = 1; i<l; ++i) {
        nameCsUns += tolower(name[i]);
    }
    return months[nameCsUns];
}

int main() {

    map <string, int> months;

    months["January"] = 31;
    months["February"] = 28;
    months["March"] = 31;
    months["April"] = 30;
    months["May"] = 31;
    months["June"] = 30;
    months["July"] = 31;
    months["August"] = 31;
    months["September"] = 30;
    months["October"] = 31;
    months["November"] = 30;
    months["December"] = 31;

    months["Jan"] = 31;
    months["Feb"] = 28;
    months["Mar"] = 31;
    months["Apr"] = 30;
    months["May"] = 31;
    months["Jun"] = 30;
    months["Jul"] = 31;
    months["Aug"] = 31;
    months["Sep"] = 30;
    months["Oct"] = 31;
    months["Nov"] = 30;
    months["Dec"] = 31;

    string name;
    cout << "Wpisz 0 by zakonczyc program\nPodaj miesiac" << endl;
    cin >> name;

    while(name != "0")
    {
        cout << "Liczba dni: " << getDays(name, months) << endl;
        cout << "Podaj miesiac" << endl;
        cin >> name;
    }

    return 0;
}


