#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int divide(int a[101][101], int left, int right, int up, int down)
{
    int s1, s2, s3 , s4, mij_orizontala, mij_verticala;
        if(left == right && up == down)
            if(a[up][left] % 2 == 0)
            {
                return a[up][left];
            }
            else return 0;
        else
        {
            if(left == right){
                mij_verticala = (up + down)/2;
                s1 = divide(a, left, right, up, mij_verticala);
                s2 = divide(a, left, right, mij_verticala+1, down);
                return s1+s2;
            }
            if(up == down){
                mij_orizontala = (left + right)/2;
                s3 = divide(a, left ,mij_orizontala, up , down);
                s4 = divide(a, mij_orizontala+1, right, up, down);
                return s3+s4;
            }
                mij_orizontala = (left + right) / 2;
                mij_verticala = (up + down) / 2;
                s1 = divide(a, left, mij_orizontala, up, mij_verticala);
                s4 = divide(a, mij_orizontala+1, right, up, mij_verticala);
                s2 = divide(a, left, mij_orizontala, mij_verticala+1, down);
                s3 = divide(a, mij_orizontala+1, right, mij_verticala+1, down);
                int max1 = s1+s2+s3+s4;
                return max1;
        }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[101][101];
    /// int **a = new int**[n]
    /// for (int i = 0 ; i < n ; i++)
    ///    {
    ///        a[i] = new int*[m];
    ///        for(int j = 0 ; j < m ; j++)
    ///    }
    for(int i = 0 ; i < n;  i++)
        for(int j = 0 ; j < m ; j++)
            cin >> a[i][j];
    cout <<divide(a, 0, m - 1, 0, n - 1);
}
