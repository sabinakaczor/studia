#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


class para{public:int a,b;};

class punkt{public:int a,b;};

class liczby{public:int a,b;};


template <typename Type>
Type findTheGreatestSum(vector<Type> tab) {
    Type result = tab[0];
    int sum = result.a + result.b;
    int temp;
    for(int i=1; i<tab.size(); ++i) {
        temp = tab[i].a + tab[i].b;
        if (temp > sum){
            sum = temp;
            result = tab[i];
        }
    }
    return result;
}

int main() {

    para par1 = {1,2};
    para par2 = {3,3};
    para par3 = {1,4};
    punkt pkt1 = {1,2};
    punkt pkt2 = {3,3};
    punkt pkt3 = {1,4};
    liczby l1 = {1,2};
    liczby l2 = {3,3};
    liczby l3 = {1,4};

    vector<para> tabPara;
    tabPara.push_back(par1);
    tabPara.push_back(par2);
    tabPara.push_back(par3);

    vector<punkt> tabPunkt;
    tabPunkt.push_back(pkt1);
    tabPunkt.push_back(pkt2);
    tabPunkt.push_back(pkt3);

    vector<liczby> tabLiczby;
    tabLiczby.push_back(l1);
    tabLiczby.push_back(l2);
    tabLiczby.push_back(l3);

    para maxPara = findTheGreatestSum<para> (tabPara);
    punkt maxPunkt = findTheGreatestSum<punkt> (tabPunkt);
    liczby maxLiczby = findTheGreatestSum<liczby> (tabLiczby);

    cout << "(" << maxPara.a << ", " << maxPara.b << ")\n";
    cout << "(" << maxPunkt.a << ", " << maxPunkt.b << ")\n";
    cout << "(" << maxLiczby.a << ", " << maxLiczby.b << ")\n";

    return 0;
}
