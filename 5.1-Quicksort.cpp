#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std ;

int RandomArray(int tab[], int n){
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


int QuickSort (int T[],int l, int p, int &num){
    int i,j, x;
    x=T[(l+p)/2];
    i=l;
    j=p;
    do {
        while (T[i]<x) {
            i++;
            num++;
        }
        num++;
        while (T[j]>x) {
            j--;
            num++;
        }
        num++;
        if (i<=j) {
            swap (T[i], T[j]);
            i++;
            j--;
            num++;
        }
    } while (i<=j);
    if (l<j) QuickSort(T, l, j, num);
    if (i<p) QuickSort(T, i, p, num);
    return 0;
}

int LongerQuickSort (int T[],int l, int p, int &num){
    int i,j, x;
    x = T[l];
    i=l+1;
    j=p;

    do {
        while (T[i]<=x && i<=p) {
            i++;
            num++;
        }
        num++;
        while (T[j]>x) {
            j--;
            num++;
        }
        num++;
        if (i<=j) {
            swap (T[i], T[j]);
            num++;
        }
    } while (i<=j);
    swap(T[l], T[j]);
    num++;
    if (l<j) LongerQuickSort(T, l, j-1, num);
    if (i<p) LongerQuickSort(T, j+1, p, num);
    return 0;
}

int main ( ) {
    const int N=100;
    int A[N];
    int B[N];
    setlocale(LC_CTYPE, "Polish");
    int comp=0;

    RandomArray(A,N);
    cout << "Tablica losowa:" << endl;
    cout << "Tablica na wejsciu: " << endl;
    Print(A, N);
    QuickSort(A, 0, N-1, comp);
    cout << "Tablica posortowana: " << endl;
    Print(A,N);
    cout << "Liczba porownan: " << comp << endl;

    comp=0;
    RandomArray(B,N);
    cout << "Tablica rosnaca:" << endl;
    cout << "Tablica na wejsciu: " << endl;
    QuickSort(B, 0, N-1, comp);
    Print(B, N);
    cout << "Tablica posortowana: " << endl;
    LongerQuickSort(B, 0, N-1, comp);
    Print(B,N);
    cout << "Liczba porownan: " << comp << endl;

    return 0;
}

