#include <iostream>
#include <cstring>

using namespace std;

/// se dau n obiecte si preturile lor. sortati descrescator dupa pret

struct obiect{
    int greutate, pret;
    float raport;
};

int cmp(const void *a, const void *b){
    obiect *ObjA = (obiect*) a;
    obiect *ObjB = (obiect*) b;
    if(ObjA -> raport > ObjB -> raport)
        return -1;
    else if(ObjA -> raport < ObjB -> raport)
        return 1;
    else return 0;
}

int main()
{
    int n, gmax;
    cin >> n >> gmax;
    obiect *v = new obiect[n];
    for(int i = 0; i < n ; i++)
    {
        cin >> v[i].greutate >> v[i].pret;
        v[i].raport = (float)v[i].pret / v[i].greutate;
    }
    /// qsort(vector, nr de elemente, sizeof(tip de element), comparator)
    qsort(v, n, sizeof(v[0]), cmp);
    int i = 0;
    int g = 0;
    float pret_rucsac = 0;
    while(i < n && g <= gmax)
    {
        if(g + v[i].greutate <= gmax)
        {
            g += v[i].greutate;
            pret_rucsac += v[i].pret;
        }
        else
        {
            pret_rucsac += (gmax - g) * v[i].raport;
            g = gmax;
        }
        i++;
    }

    cout << pret_rucsac;
    return 0;
}
