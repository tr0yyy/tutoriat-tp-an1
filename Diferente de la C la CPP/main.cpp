#include <stdio.h> /// SPECIFIC LIMBAJULUI C
#include <stdlib.h> /// SPECIFIC LIMBAJULUI C
#include <iostream> /// SPECIFIC LIMBAJULUI C++
#include <cstdlib> /// SPECIFIC LIMBAJULUI C++

using namespace std; /// SPECIFIC LIMBAJULUI C++

/// transmiterea parametrilor in C++ se face prin referinta,
/// nu prin pointer ca in C

void dublul_lui_n_in_C(int *n) /// transmitere via pointer
{
    (*n) *= 2;
}

void dublul_lui_n_in_Cpp(int &n) /// transmitere via referinta
{
    n *= 2;
}

/// vectorii nu se transmit prin pointeri in C++
/// ci pur si simplu ca la alocarea statica, doar ca fara
/// specificarea memoriei (CAZ SPECIAL MATRICE, VEZI LINIA 40)

void modif_vector_in_C(int **v) /// in C
{
    /// foloseam (*v) (gen (*v)[1], (*v)[2])
}

void modif_vector_in_Cpp(int v[]) /// in C++
{
    /// FOLOSIM EFECTIV V (gen v[1], v[2])
}

void modifc_matrice_in_C(int ***a) /// in C
{
    /// foloseam (*a) (gen (*a)[1][1], (*a)[2][1])
}

/// LA MATRICE, COMPILATORUL ARE NEVOIE SA STIE UN NUMAR
/// DE COLOANE, ACESTA TREBUIE SA FIE SCRIS
void modif_matrice_in_Cpp(int a[][101]) /// in C++
{
    /// FOLOSIM EFECTIV A (gen a[1][1], a[2][1])
}

int main()
{
    int n;
    scanf("%d", &n); /// citire variabila in C
    cin >> n; /// citire variabila in C++
    printf("%d\n", n); /// afisare variabila in C
    cout << n << endl; /// afisare variabila in C++

    /// ALOCARE DINAMICA
    int *vc = (int*) malloc (n * sizeof(int));
    int *vcpp = new int[n];

    /// realocarea vectorului nu este posibila in C++,
    /// deci nu avem alternativa pentru realloc
    /// decat sa alocam manual un alt vector si sa copiez valorile

    free(vc); /// stergere vector in C
    delete [] vcpp; /// stergere vector in C++

    /// apelarea functiilor cu transmitere prin parametru este diferita

    int a = 10;
    dublul_lui_n_in_C(&a); /// in C
    dublul_lui_n_in_Cpp(a); /// in C++

    int *vtest = new int[n];
    modif_vector_in_C(&vtest); /// pentru C
    modif_vector_in_Cpp(vtest);

}


