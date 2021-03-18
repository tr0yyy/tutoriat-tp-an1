#include <iostream>

using namespace std;

/*int divide(int v[100], int st, int dr, int max1)
{
    int s1, s2, mij;
    if(st == dr)
    {
        if(v[st] % 2 != 0)
            return 1;
        return 0;
    }
    mij = (st + dr) / 2;
    s1 = divide(v, st, mij);
    s2 = divide(v, mij + 1, dr);
    return s1 | s2;
}
Verifica daca exista elemente impare in vector
*/

int divide(int v[100], int st, int dr)
{
    int s1, s2, mij;
    if(dr == st)
    {
        return 1;
    }
    mij = (st + dr) / 2;
    if(divide(v, st, mij) == 1 && divide(v, mij + 1, dr) == 1 && v[mij] <= v[mij + 1])
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int v[100], n, i;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>v[i];
    cout<<divide(v, 0, n-2);
    return 0;
}
