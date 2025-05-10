#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX = 2147483647;

int losowa(int tab[], int n) {
    for (int i = 1; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

int drukuj(int tab[], int n) {
    for (int i = 1; i <= n; i++)
        cout << tab[i] << " ";
    cout << endl;
    return 0;
}

int StackSort(int tab[], int n) {
    int i, j, left, older;
    int buildStack = 0;
    int destStack = 0;

    for (i = 2; i <= n; i++) {
        j = i;
        int k = j / 2;
        while (j > 1) {
            buildStack++;
            if (tab[k] < tab[j]) {
                swap(tab[j], tab[k]);
                j = k;
                k = j / 2;
            } else {
                break;
            }
        }
    }

    cout << "Kopiec przed rozbiorka:" << endl;
    drukuj(tab, n);
    cout << "Liczba porownan podczas budowania kopca: " << buildStack << endl;


    for (i = n; i > 1; i--) {
        swap(tab[1], tab[i]);
        j = 1;
        left = 2;

        while (left < i) {
            destStack++;
            if (left + 1 < i && tab[left + 1] > tab[left]) {
                older = left + 1;
            } else {
                older = left;
            }

            destStack++;
            if (tab[older] <= tab[j]) break;

            swap(tab[j], tab[older]);
            j = older;
            left = 2 * j;
        }
    }

    cout << "Liczba porownan podczas rozbiorki kopca: " << destStack << endl;
    cout << "Calkowita liczba porownan: " << destStack + buildStack << endl << endl;
    return 0;
}

int main() {
    const int N = 100;
    int A[N + 1];

    setlocale(LC_CTYPE, "Polish");


    cout << "LOSOWA" << endl;
    losowa(A, N + 1);
    cout << "Tablica przed posortowaniem:" << endl;
    drukuj(A, N);
    cout << endl;

    StackSort(A, N);
    cout << "Tablica po posortowaniu:" << endl;
    drukuj(A, N);
    cout << endl;


    cout << "ROSNACA" << endl;
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }

    cout << "Tablica przed posortowaniem:" << endl;
    drukuj(A, N);
    cout << endl;

    StackSort(A, N);
    cout << "Tablica po posortowaniu:" << endl;
    drukuj(A, N);
    cout << endl;

    cout << "MALEJACA" << endl;
    for (int i = 1; i <= N; i++) {
        A[i] = N-i;
    }

    cout << "Tablica przed posortowaniem:" << endl;
    drukuj(A, N);
    cout << endl;

    StackSort(A, N);
    cout << "Tablica po posortowaniu:" << endl;
    drukuj(A, N);
    cout << endl;

    return 0;
}
