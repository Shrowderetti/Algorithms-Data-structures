#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

const int N = 10;

bool visited[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

void DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (int u = 0; u < N; u++)
    {
        if (A[v][u] == 1 && !visited[u])
        {
            DFS(u);
        }
    }
}

void DFS_B(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (int u = 0; u < N; u++)
    {
        if (B[v][u] == 1 && !visited[u])
        {
            DFS_B(u);
        }
    }
}

void BFS(int v)
{
    queue q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < N; i++)
        {
            if (A[v][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS_B(int v)
{
    queue q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < N; i++)
        {
            if (B[v][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void resetVisited()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
}

int main( )
{
	int i;

	setlocale(LC_CTYPE, "Polish");
    cout << "Graf z zadania" << endl;
	cout << "Przejscie grafu w glab - DFS(1):" << endl;
	DFS ( 1 );
	cout << endl;

    resetVisited();

    cout << "Przejscie grafu wszerz - BFS(1):" << endl;
	BFS ( 1 );
	cout << endl << endl;

    resetVisited();
    cout << "Graf wlasny" << endl;
    cout << "Przejscie grafu w glab - DFS(1):" << endl;
    DFS_B ( 1 );
    cout << endl;

    resetVisited();

    cout << "Przejscie grafu wszerz - BFS(1):" << endl;
    BFS_B ( 1 );
    cout << endl;

	return 0;
}

