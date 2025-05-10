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
//prev jest wskaŸnikiem do poprzedniego elementu
//data zawiera dane
struct Node
{
    Node * next;
    Node * prev;
    int data;
};

//& przed nazw¹ zmiennej jest przekazanie tej zmiennej przez referencjê
//referencje powoduj¹, ¿e w chwili przekazywania argumentów,
//pracujemy na orygina³ach zmiennych, poniewa¿ przekazywane s¹ ich adresy

//wstawianie elementu na pocz¹tek listy
void insert_front (Node * &head, int data )
{
    Node * p = new Node;

    //do pola data elementu wskazywanego przez p wstaw data z argumentu funkcji
    p->data = data;

    //je¿eli lista jest pusta
    if(head == NULL) {
        //head ustaw na element wskazywany przez p
        head = p;
        //wskaŸnik next elementu wskazywanego przez head ustaw na NULL
        head->next = NULL;
        //wskaŸnik prev elementu wskazywanego przez head ustaw na NULL
        head->prev = NULL;
    } else {

        // wskaŸnik next elementu wskazywanego przez p ustaw na head
        p->next = head;

        //niech poprzednik prev elementu wskazywanego przez head wskazuje na p
        head->prev = p;

        //head przepnij na p
        head = p;
        //poprzednik head ustaw na NULL
        head->prev = NULL;
    }
}

//usuwanie elementu wskazywanego przez p
void delete_p (Node * &head, Node *p)
{
    //wskaŸnik do poprzedniego elementu
    Node * prev = NULL;

    //jeœli p wskazuje na pierwszy element
    if (p == head) {
        //przepnij head na nastêpny element
        head = p->next;

        //jako poprzednik prev dla head ustaw NULL
        head->prev = NULL;

        //zwolnij pamiêc p
        delete p;

    }else
    {
        //ustaw wskaŸnik next elementu poprzedzaj¹ce p na element nastêpny po p
        (p->prev)->next = p->next;
        //je¿eli p->next !=NULL
        //ustaw wskaŸnik prev elementu nastêpnego po p na element poprzedzaj¹cy p
        if (p->next != NULL){
            (p->next)->prev = p->prev;
        }
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
        if (p->data == data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

//policz elementy na liœcie
int size( Node * p )
{
    int size = 0;
    while (p){
        size++;
        p=p->next;
    }
    cout << "Liczba elementów listy: " << size << endl;
    return 0;
}

//wypisz elementy listy
void print ( Node * head )
{
    int i = 0;
    Node * p = head;
    while (p){
        i++;
        cout << i << ": " << p->data << endl;
        p=p->next;
    }
}

int main ()
{
    Node * L, *p;
    int i, data;

    L=NULL;

    setlocale(LC_CTYPE, "Polish");

    //wstawiamy do listy 20 wygenerowanych liczb pseudolosowych
    srand ( time ( NULL ) );
    for(i = 0; i < 20; i++){
        insert_front(L, rand() % 100);
    }

    //wypisujemy elementy listy
    print(L);

    cout << "wprowadŸ liczbê do usuniêcia: ";
    cin >> data;

    cout << endl;

    p = find (L, data);

    if (p!=NULL) delete_p (L, p);
    else
        cout << "elementu brak na liœcie" <<endl;
    size (L);
    print(L);

    return 0;

}
