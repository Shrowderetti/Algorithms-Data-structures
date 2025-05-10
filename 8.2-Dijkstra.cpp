//algorytm Dijkstry

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 2147483647;

const int N = 6; //ilość wierzchołków w grafie

int A[N][N]={
        {0, 4, 4, 1, 0, 0}, //0
        {4, 0, 3, 0, 3, 0}, //1
        {4, 3, 0, 2, 1, 5}, //2
        {1, 0, 2, 0, 0, 5}, //3
        {0, 3, 1, 0, 0, 1}, //4
        {0, 0, 2, 5, 1, 0}, //5
};

bool visited[N] = {0, 0, 0, 0, 0, 0};
int dist[N] = {0, MAX, MAX, MAX, MAX, MAX};
int previous[N] = {-1, -1, -1, -1, -1, -1};

void print(int i)
{
    if (previous[i] != -1) {
        print(previous[i]);
    }
    cout << " " << i << " ";
}

int findMin() {
    int min = -1;
    int mindist = MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] < mindist) {
            min = i;
            mindist = dist[i];
        }
    }
    return min;
}

int main( ){
    int v = 0;
    int i;
    setlocale(LC_CTYPE, "Polish");
    while(v!=-1){
        visited[v]=1;
        for (i = 0; i < N; i++) {
            if (A[v][i] != 0 && !visited[i] && dist[i] > dist[v] + A[v][i]) {
                dist[i] = dist[v] + A[v][i];
                previous[i] = v;
            }
        }
        v=findMin();
    }

    for( int i = 0; i < N; i++ )
        cout << setw ( 3 ) << i;
    cout << endl;

    for( int i = 0; i < N; i++ )
        cout << setw ( 3 ) << dist[i];
    cout << endl;

    for( int i = 0; i < N; i++ )
        cout << setw ( 3 ) << previous[i];
    cout << endl;
    for (int i = 1; i < N; i++) {
        cout << "Koszt sciezki 0 do " << i << " wynosi: " << dist[i]<<endl;
        cout <<"Sciezka: ";
        print(i);
        cout << endl;
    }
}