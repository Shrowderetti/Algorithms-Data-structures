#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomArray(int tab[], int n){
    srand(time(0));
    for (int i=0; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

int Print(int tab[], int n){
    for (int i=0; i < n; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
    return 0;
}

int SelectSort(int tab[], int n, int l){
    for (int i=0; i < n-1; i++){
        int min = tab[i];
        int k = i;
        for (int j = i + 1; j < n; j++){
            l++;
            if (tab[j] < min){
                min = tab[j];
                k = j;
            }
        if (tab[k]<tab[i]) swap (tab[i],tab[k]);
        }
    }
    cout << "Liczba porownan z dzialania algorytmu: " << l << endl;
    cout << "Liczba porownan ze wzoru: " << n*(n-1)/2 << endl;
    return  0;
}

int main ( ) {
    int N = 50;
    while (N!=200) {
        int T[N];
        int l = 0;
        cout << "Sortowanie tablicy z " << N << " liczbami" << endl;
        RandomArray(T, N);
        cout << "Tablica przed sortowaniem:" << endl;
        Print(T, N);
        SelectSort(T, N, l);
        cout << "Tablica posortowana:" << endl;
        Print(T, N);
        N+=50;
        cout << endl;
    }
}

