#include <iostream>
#include <cstdlib> // rand()
#include <ctime> // srand()
#include <fstream>

using namespace std;

ifstream fin("fisierulmeu.in");
ofstream fout("fisierulmeu.out");

int main()
{
    srand(time(NULL));
    /// 0 si 9
    int numarul_meu = rand() % 10;
    cout << numarul_meu << endl;
    /// 0 si 100
    numarul_meu = rand() % 101;
    cout << numarul_meu << endl;
    /// 20 si 80
    numarul_meu = rand() % 61 + 20;
    cout << numarul_meu << endl;

    /// 100 de numere 50 la 150
    ofstream f2out("numere_random.txt");
    for(int i = 1 ; i <= 100 ; i++)
        f2out << rand() % 101 + 50 << " ";
    f2out.close();

    ifstream f2in("numere_random.txt");
    for(int i = 1 ; i <= 100 ; i++)
    {
        int x;
        f2in >> x;
        cout << x << " ";
    }
}
