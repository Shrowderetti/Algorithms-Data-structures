#include <iostream>

//potrzebne do srand
#include <cstdlib>

//potrzebne do time
#include <ctime>

//potrzebne do polskich znaków
#include <locale.h>

using namespace std;

//struktura Node
//next jest wskaŸnikiem do nastêpnego elementu
//data zawiera dane
struct Node
{
	Node * next;
	int data;
};

//& przed nazw¹ zmiennej jest przekazanie tej zmiennej przez referencjê
//referencje powoduj¹, ¿e w chwili przekazywania argumentów,
//pracujemy na orygina³ach zmiennych, poniewa¿ przekazywane s¹ ich adresy

//wstawianie elementu na pocz¹tek listy
void insert_front (Node * &head, int data )
{
	Node * p = new Node;
    p->data = data;
    p->next = head;
    head = p;
}

//usuwanie elementu wskazywanego przez p
void delete_p (Node * &head, Node *p)
{
	//wskaŸnik do poprzedniego elementu
	Node * prev = NULL;

	//jeœli p wskazuje na pierwszy element
	if(head==p){
		//przepnij head na nastêpny element
        head = head->next;

		//zwolnij pamiêc p
		delete p;

    }else
        {
        //prev ustaw na pierwszym elemencie
        prev = head;
        //przepinaj prev dopóki nie znajdzie siê przed p
        while (prev->next != p){
            prev = prev->next;
        }
        //ustaw wskaŸnik next elementu wskazywanego przez prev na element nastêpny po p
        prev->next = p->next;
        //zwolnij pamiêæ p
        delete p;
        }
}


//znajdŸ data na liœcie i zwróæ wskaŸnik do niego
Node * find( Node * p, int data ){
	//sprawdzaj czy data elementu wskazywanego przez p = data z argumentu funkcji
	//przepinaj p
	//zwróæ p lub NULL
    while (p){
        if (p->data == data) return p;
        p=p->next;
    }
    return NULL;
}

//policz elementy na liœcie
int size( Node * p )
{
	int size = 0;

	// przepinaj p na nastêpny element i zwiêkszaj licznik
    while (p) {
        size++;
        p = p->next;
    }
	cout << "Liczba elementów listy: " << size << endl;
	return 0;
}

//wypisz elementy listy
void print ( Node * head )
{
	int i = 0;
	Node * p = head;
	//przepinaj p na nastêpny element i wypisuj pole data
    while (p) {
        cout << ++i << ": " << p->data << endl;
        p=p->next;
    }
    cout << endl;
	//w postaci i: data, np 1: 23 2:34 4:9 itd

	cout << endl;
}

int main ()
{
    Node *L, *p;
    int i, data;

    L = NULL;

    setlocale(LC_CTYPE, "Polish");

    //wstaw do listy L 20 wygenerowanych liczb pseudolosowych
    srand(time(NULL));
    for (i = 0; i < 20; i++) {
        insert_front(L, rand() % 100);
    }
    //wypisz elementy listy
    print(L);
    //wczytaj liczbê do usuniêcia
    cout << "wprowadź liczbę do usunięcia: ";
    cin >> data;
    //sprawdŸ czy liczba istnieje na liœcie
    p = find(L, data);
    //jeœli tak, usuñ j¹, jeœli nie, napisz, ¿e elementu brak na liœcie
    if (p != NULL) delete_p(L, p);
    else
        cout << "element brak na liście" << endl;
    //wypisz iloœæ elementów
    size(L);
    //wypisz elementy listy
    print(L);

    return 0;
}