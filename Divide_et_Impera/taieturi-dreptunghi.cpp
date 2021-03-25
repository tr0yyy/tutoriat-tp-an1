#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream f("test.in");
ofstream g("test.out");

/// nu e divide et impera.
/// cred ca se poate considera divide daca in loc de alea 2 foruri bagam un quick sort
/// sau merge sort, care se bazeaza pe divide et impera.

int main()
{
    int n, m, nr, vx[101], vy[101], i, j, max1 = 0, max2 = 0;
    f>>n>>m>>nr;
    for(i = 0; i < nr; i++)
    {
        f>>vx[i]>>vy[i];
    }
    vx[nr] = 0;
    vy[nr] = 0;
    vx[nr + 1] = n;
    vy[nr + 1] = m;
    nr = nr + 2;
    for(i = 0; i < nr - 1; i++)
        for(j = i + 1; j < nr; j++)
            if(vx[i] > vx[j])
                swap(vx[i], vx[j]);
    for(i = 0; i < nr - 1; i++)
        for(j = i + 1; j < nr; j++)
            if(vy[i] > vy[j])
                swap(vy[i], vy[j]);
    for(i = 0; i < nr - 1; i++)
        if(vx[i + 1] - vx[i] > max1)
            max1 = vx[i + 1] - vx[i];
    for(i = 0; i < nr - 1; i++)
        if(vy[i + 1] - vy[i] > max2)
            max2 = vy[i + 1] - vy[i];
    g<<"Aria maxima este: "<<max1 * max2;
    return 0;
}