#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

int n;

struct slistEl
{
    slistEl * next;
    int data;
};

slistEl ** A;
slistEl ** B;
bool * visited;

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

void DFS ( slistEl **graph, int v )
{
    slistEl * p;
    visited[v]=true;
    cout << v << " ";
    for (p = graph[v];p; p = p->next)
    {
        if (!visited[p->data])
        {
            DFS(graph, p->data);
        }
    }
}

void BFS ( slistEl **graph, int v )
{
    queue q;
    slistEl *p;
    q.push(v);
    visited[v] = true;
    while (!q.empty()){
        v = q.front();
        cout << v << " ";
        q.pop();
        for (p = graph[v];p; p = p->next)
        {
            if (!visited[p->data])
            {
                q.push(p->data);
                visited[p->data] = true;
            }
        }
    }
}

int main( )
{
    int i, vs, ve;
    slistEl *p;

    setlocale(LC_CTYPE, "Polish");

    const int n = 4; //ilosc wierzcholków
    const int m = 8; //ilosc sasiadów

    int E[m][2] = { {0,3},
                    {0,1},
                    {1,2},
                    {1,0},
                    {2,3},
                    {2,1},
                    {3,2},
                    {3,0} }; //kolejne krawêdzie

    A = new slistEl * [ n ];
    visited = new bool [ n ];

    for( i = 0; i < n; i++ )
    {
        A [ i ] = NULL;
        visited [ i ] = false;
    }

    for( i = 0; i < m; i++ )
    {
        vs = E[i][0];
        ve = E[i][1];

        p = new slistEl;
        p->data = ve;
        p->next = A [ vs ];
        A [ vs ] = p;
    }

    for( i = 0; i < n; i++ )
    {
        cout << "A [ " << i << " ] =";
        p = A [ i ];
        while( p )
        {
            cout << setw ( 3 ) << p->data;
            p = p->next;
        }
        cout << endl;
    }

    cout << "Przejecie grafu w glab - DFS(0):" << endl;
    DFS ( A, 0 );
    cout << endl;

    for( i = 0; i < n; i++ )
        visited [ i ] = false;

    cout << "Przejœcie grafu wszerz - BFS(0):" << endl;
    BFS ( A, 0 );
    cout << endl << endl;


    int F[m][2] = { {0,1},
                    {0,2},
                    {1,3},
                    {1,0},
                    {2,0},
                    {2,3},
                    {3,2},
                    {3,1} };

    B = new slistEl * [ n ];
    visited = new bool [ n ];

    for( i = 0; i < n; i++ )
    {
        B [ i ] = NULL;
        visited [ i ] = false;
    }

    for( i = 0; i < m; i++ )
    {
        vs = F[i][0];
        ve = F[i][1];

        p = new slistEl;
        p->data = ve;
        p->next = B [ vs ];
        B [ vs ] = p;
    }

    for( i = 0; i < n; i++ )
    {
        cout << "B [ " << i << " ] =";
        p = B [ i ];
        while( p )
        {
            cout << setw ( 3 ) << p->data;
            p = p->next;
        }
        cout << endl;
    }

    cout << "Przejecie grafu w glab - DFS(0):" << endl;
    DFS ( B, 0 );
    cout << endl;

    for( i = 0; i < n; i++ )
        visited [ i ] = false;

    cout << "Przejœcie grafu wszerz - BFS(0):" << endl;
    BFS ( B, 0 );
    cout << endl;

    return 0;
}

