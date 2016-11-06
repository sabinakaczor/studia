#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int main()
{

    //ZADANIE 1A

   /* vector <string> words;
    string word;
    cout << "Podaj 20 slow\n";
    for(int i=0; i<20; ++i) {
        cin >> word;
        words.push_back(word);
    }

    if(words.size() > 0) {
        cout << "Slowa wpisane do tablicy:\n";
        for(int j=0; j < words.size(); ++j) {
            cout << words[j] << " ";
        }
    }*/


    //ZADANIE 1B

    vector<string> content;

    fstream plik1, plik2, plik3;
    string line;

    plik1.open("plik1.txt",ios::in);

    if(plik1.is_open()) {
        plik1 >> line;
        while(!plik1.eof()) {
            content.push_back(line);
            content.push_back(" ");
            plik1 >> line;
        }
        plik1.close();
    }else {
        cout << "blad otwarcia plik1";
    }



    plik2.open("plik2.txt",ios::in);

    if(plik2.is_open()) {
        plik2 >> line;
        while(!plik2.eof()) {
            content.push_back(line);
            content.push_back(" ");
            plik2 >> line;
        }
        plik2.close();
    } else {
        cout << "blad otwarcia plik2";
    }

    plik3.open("dane.txt", ios::out);
    if(plik3.is_open()==true) {
        for(int i=0; i < content.size(); i++) {
            plik3 << content[i];
        }
        plik3.close();
    } else {
        cout << "nie udalo sie otworzyc plik3";
    }

    return 0;
}

