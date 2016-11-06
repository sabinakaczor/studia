#include <string>
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;
int main()
{
    stack<string> content;
    stack<string> temp;

    fstream plik1, plik2, plik3;
    string line;

    plik1.open("plik1.txt",ios::in);

    if(plik1.is_open()) {
        plik1 >> line;
        while(!plik1.eof()) {
            content.push(line);
            content.push(" ");
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
            content.push(line);
            content.push(" ");
            plik2 >> line;
        }
        plik2.close();
    } else {
        cout << "blad otwarcia plik2";
    }

    plik3.open("dane.txt", ios::out);
    if(plik3.is_open()) {
        while(!content.empty()) {
            temp.push(content.top());
            content.pop();
        }
        while(!temp.empty()) {
            plik3 << temp.top();
            temp.pop();
        }
        plik3.close();
    } else {
        cout << "nie udalo sie otworzyc plik3";
    }


    return 0;
}

