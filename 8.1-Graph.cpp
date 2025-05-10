#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

const int N = 10;

bool visited[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct slistEl
{
    slistEl * next;
    int data;
};

class queue
{
private:
    slistEl * head;
    slistEl * tail;

public:
    queue( );
    ~queue( );
    bool empty ( void );
    int  front ( void );
    void push ( int v );
    void pop ( void );
};

class stack
{
private:
    slistEl * S;

public:
    stack( );
    ~stack( );
    bool empty ( void );
    int  top ( void );
    void push ( int v );
    void pop ( void );
};

stack S; //deklaracja stosu dla DFS

int P[N]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //deklaracja tablicy poprzedników dla BFS

queue::queue( )
{
    head = tail = NULL;
}

queue::~queue( )
{
    while( head ) pop( );
}

bool queue::empty ( void )
{
    return !head;
}

int queue::front ( void )
{
    if( head ) return head->data;
    else     return MAXINT;
}

void queue::push ( int v )
{
    slistEl * p = new slistEl;
    p->next = NULL;
    p->data = v;
    if( tail ) tail->next = p;
    else     head = p;
    tail = p;
}

void queue::pop ( void )
{
    if( head )
    {
        slistEl * p = head;
        head = head->next;
        if( !head ) tail = NULL;
        delete p;
    }
}

stack::stack( )
{
    S = NULL;
}

stack::~stack( )
{
    while( S ) pop( );
}

bool stack::empty ( void )
{
    return !S;
}

int stack::top ( void )
{
    return S->data;
}

void stack::push ( int v )
{
    slistEl * e = new slistEl;
    e->data    = v;
    e->next = S;
    S = e;
}

void stack::pop ( void )
{
    if( S )
    {
        slistEl * e = S;
        S = S->next;
        delete e;
    }
}

bool DFS ( int v, int ve, int A[N][N] )
{
    visited[v] = true;
    S.push(v);
    if (v == ve) return true;
    for (int u = 0; u < N; u++){
        if (A[v][u] && !visited[u]){
            if (DFS(u, ve, A)) {
                return true;
            }
        }
    }
    S.pop();
    return false;
}

bool BFS ( int vs, int ve , int A[N][N])
{
    P[vs]=-1;
    queue q;
    q.push(vs);
    visited[vs] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v == ve){
            return true;
        }
        for (int i = 0; i < N; i++){
            if (!visited[i] && A[v][i] == 1){
                q.push(i);
                visited[i] = true;
                P[i] = v;
            }
        }
    }
    return false;
}

int main( )
{
    int i, v, x;

    int vs, ve, xs, xe; //wierzchołek początkowy i końcowy

    int A[N][N] = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
            { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            { 0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
            { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
            { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
            { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
            { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
    };
    vs = 1;
    ve = 6;
    int B[N][N] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            { 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
            { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
            { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
            { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            { 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
            { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
    };
    xs = 1;
    xe = 9;
    setlocale(LC_CTYPE, "Polish");

    cout << "Sciezka z zadania - DFS:" << endl;
    if( !DFS ( vs, ve , A) ) cout << "BRAK";
    else {
        while (!S.empty()) {
            cout << S.top() << " ";
            S.pop();
        }
    }
    cout << endl;

    for( i = 0; i < N; i++ ) {
        visited[i] = false;
    }

    cout << "Sciezka z zadania - BFS:" << endl;
    if( !BFS ( vs, ve , A) ) cout << "BRAK";
    else {
        v = ve;
        while (v > -1){
            cout << v << " ";
            v = P[v];
        }
    }
    cout << endl;

    for( i = 0; i < N; i++ ) {
        visited[i] = false;
    }

    cout << "Sciezka wlasna DFS:" << endl;
    if( !DFS ( xs, xe, B ) ) cout << "BRAK";
    else
    {
        while (!S.empty()) {
            cout << S.top() << " ";
            S.pop();
        }
    }
    cout << endl;

    for( i = 0; i < N; i++ ) {
        visited[i] = false;
    }

    cout << "Sciezka wlasna BFS:" << endl;
    if( !BFS ( xs, xe, B ) ) cout << "BRAK";
    else
    {
        x = xe;
        while (x > -1) {
            cout << x << " ";
            x = P[x];
        }
    }
    cout << endl;
    return 0;
}

