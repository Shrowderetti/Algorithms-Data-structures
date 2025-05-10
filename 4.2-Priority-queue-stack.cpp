#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX = 2147483647;

const int N = 100;


struct QueueEl
{

    int priority, data;
};


class priorityqueue
{
private:
    QueueEl T[ N ];
    int n;

public:
    priorityqueue( );
    ~priorityqueue( );
    bool empty ( void );
    int findmaxdata ( void );
    int findmaxpriority ( void );
    void insert ( int priority, int data );
    void deletemax ( void );
    void print ( void);
};


priorityqueue::priorityqueue( )
{
    n=0;
}

priorityqueue::~priorityqueue( )
{

}


bool priorityqueue::empty ( void )
{
    return !n;
}

int priorityqueue::findmaxdata ( void )
{
    if (n) return T[1].data;
    else        return MAX;
}

int priorityqueue::findmaxpriority ( void )
{
    if (n) return T[1].priority;
    else        return MAX;
}

void priorityqueue::insert ( int priority, int data )
{
    int i, j;
    int count=0;
    n++;
    i=n;

    T[i].data = data;
    T[i].priority = priority;
    j = i/2;
    while ((i>1)&&(++count)&&(T[i].priority>T[j].priority)){
        swap(T[i], T[j]);
        i=j;
        j=i/2;
    }
    cout << "Ilosc porownan: " << count << endl;
}


void priorityqueue::deletemax ( void )
{
    int i, d, p, older;

    p = T [ n ].priority;
    d = T [ n ].data;

    n--;

    if(n>0)
    {

        i=1;
        T [ i ].priority = p;
        T [ i ].data = d;

        while( i < n ) {
            if ((i * 2 + 1) <= n) {
                if (T[i * 2].priority > T[(i * 2) + 1].priority) older = i * 2;
                else older = (i * 2) + 1;
            } else if (i * 2 <= n) older = i*2;
            if (p < T[older].priority) {
                swap(T[i], T[older]);
                i = older;
            } else break;
        }
    }
}


int main( )
{
    priorityqueue Q;
    int i, p, v;

    setlocale(LC_CTYPE, "Polish");

    srand ( time ( NULL ) );

    cout << "wprowadzone elementy w postaci element:priorytet\n";

    for( i = 1; i <= 10; i++ )
    {
        v = i;
        p = rand( ) % 100;
        cout << v << "|" << p << endl;
        Q.insert (p, v);
    }

    //¿eby sprawdziæ czy dzia³a samo insert nale¿y usun¹æ poni¿sze
    //dodaæ wypisywanie tablicy i sprawdziæ (rêcznie) czy jest sep³niony warunek kopca

    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";

    while ( !Q.empty( ) )
    {
        cout << Q.findmaxdata( ) << "|" << Q.findmaxpriority( ) << endl;
        Q.deletemax( );
    }
}
