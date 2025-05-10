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

int P[N]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //deklaracja tablicy poprzednikï¿½w dla BFS

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

void printG(int A[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if (A[i][j]!=99) {
                cout << A[i][j] << " ";
            } else cout << "  ";
        }
        cout<<endl;
    }
}
void clear_v()
{
    for(int i = 0; i < N; i++ )
    {
        visited [ i ] = false;
        P[i]=-1;
    }
}

bool DFS ( int v, int pop_v,int A[N][N])
{
    visited[v]=true;
    S.push(v);
    for(int i=0;i<N;i++)
    {
        if (i == v) continue;
        if(A[v][i]==1)
        {
            if(visited[i]==false)
            {
                if(DFS(i,v,A))
                {
                    return true;
                }
            }
            else if(visited[i] && i != pop_v)
            {
                return true;
            }
        }
    }
    S.pop();
    return false;
}

void stack_p()
{
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
}
int main( )
{

    int A[N][N] = {
            { 99, 1, 2, 3, 4, 5, 6, 7, 8, 9},
            { 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
            { 2, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            { 3, 0, 1, 0, 1, 1, 0, 0, 0, 0},
            { 4, 0, 0, 1, 0, 0, 0, 0, 1, 0},
            { 5, 1, 0, 1, 0, 0, 1, 0, 1, 0},
            { 6, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            { 7, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            { 8, 0, 0, 0, 1, 1, 0, 0, 0, 1},
            { 9, 1, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    int B[N][N]= {
            {99, 1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {2, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {3, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {4, 0, 0, 1, 0, 1, 0, 0, 0, 0},
            {5, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {6, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            {7, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {8, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {9, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    clear_v();
    cout<<"Graf nr.1:"<<endl;
    printG(A);
    cout<<endl;
    if(DFS(1,-1,A))
    {
        cout<<"Graf cykliczny!"<<endl;
        stack_p();
    }
    else
    {
        cout<<"Graf acykliczny."<<endl;
        stack_p();
    }

    cout<<endl<<endl;
    clear_v();
    cout<<"Graf nr.2:"<<endl;
    printG(B);
    if(DFS(1,-1,B))
    {
        cout<<"Graf cykliczny!"<<endl;
        stack_p();
    }
    else
    {
        cout<<"Graf acykliczny."<<endl;
        stack_p();
    }

    return 0;
}
