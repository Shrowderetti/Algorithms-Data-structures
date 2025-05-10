#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N=10;

class queue
{
private:
    int T[N];
    int first, size;

public:
    queue( );
    ~queue( );
    bool empty ( );
    int front ();
    void enqueue ( int v );
    void dequeue ( );
    void print ( );
};

queue::queue( )
{
    first = 0;
    size = 0;
};

queue::~queue( )
{
};

bool queue::empty ( void )
{
    return size == 0;
};

int queue::front()
{
    return T[first];
};

void queue::enqueue ( int v )
{
    if (size < N){
        int p = (first + size);
        T[p]=v;
        size++;
    }
};

void queue::dequeue ( )
{
    if(first < N){
        first=first+1;
        size--;
    } else if (first = N) {
        first = 0;
        size--;
    }
};

void queue::print()
// skomentowaæ kod - wyjaœniæ jak dzia³a
{
    int i, n;
    if (size) { //Jesli tablica nie jest pusta
        for (int i = 0; i < size; i++){ //Zaczynamy petle z inkrementujacym sie i ktore przeriwe petle gdy przekroczy rozmiuar tablicy
            n = first + i; //n przyjmuje wartość nastepną od i
            if (n >= N) //Sprawdzamy cyklicznosc tabeli
                n = n - N;
            cout << T[n] << " "; //Wypisujemy wartosc
        }
        cout << endl;
    }
};

int main( )
{
    queue Q;
    int i, v;

    srand ( time ( NULL ) );

    for( i = 1; i <= 10; i++ )
    {
        v = rand( ) %  100;
        Q.enqueue ( v );
    }

    Q.print();
    if (!Q.empty())
        cout << "Front: " << Q.front() << endl;

    for( i = 1; i <= 10; i++ ) {
        Q.dequeue();
        Q.dequeue();
        Q.print();
        if (!Q.empty())
            cout << "Front: " << Q.front() << endl;
        v = rand( ) %  100;
        Q.enqueue ( v );
        Q.print();
        if (!Q.empty())
            cout << "Front: " << Q.front() << endl;
    }

    Q.dequeue();
    Q.print();
    if (!Q.empty())
        cout << "Front: " << Q.front() << endl;

    return 0;

};
