#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctime>

using namespace std ;

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

int InsertSort(int tab[], int n, int l){
    for (int i = 1; i < n; i++){
        int x = tab[i];
        int j = i - 1;
        if (j < 0 || tab[j]<x) l++;
        while (j >= 0 && tab[j]>x){
            tab[j+1]=tab[j];
            j = j -1;
            l++;
        }
        tab[j+1] = x;
    }
    cout << "liczba porownan: " << l << endl;
    l = 0;
    return 0;
}

int IncrTab(int tab[], int n){
    for (int i = 1; i < n; i++){
        tab[i] = i;
    }
    return 0;
}

int DecrTab(int tab[], int n){
    int x = 100;
    for (int i = 0; i < n; i++){
        tab[i] = x;
        x--;
    }
    return 0;
}

int main ( ) {
    const int N=100;
    int A[N];
    int l = 0;
    bool p = false;

    setlocale(LC_CTYPE, "Polish");

    cout<<"LOSOWA"<<endl;
    RandomArray(A, N);
    cout<<"Tablica przed posortowaniem:"<<endl;
    Print(A, N);
    cout<<endl;
    InsertSort(A, N, l);
    cout<<"Tablica po posortowaniu:"<<endl;
    Print(A, N);
    cout<<endl;

    cout<<"ROSNACA"<<endl;
    IncrTab(A, N);
    cout<<"Tablica przed posortowaniem:"<<endl;
    Print(A, N);
    cout<<endl;
    InsertSort(A, N, l);
    cout<<"Tablica po posortowaniu:"<<endl;
    Print(A, N);
    cout<<endl;

    cout<<"MALEJACA"<<endl;
    DecrTab(A, N);
    cout<<"Tablica przed posortowaniem:"<<endl;
    Print(A, N);
    cout<<endl;
    InsertSort(A, N, l);
    cout<<"Tablica po posortowaniu:"<<endl;
    Print(A, N);
    cout<<endl;
    return 0;

}
