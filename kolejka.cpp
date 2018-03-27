#include "kolejka.hpp"
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;



/*
  funkcja odpowiedzialna za wstawienie elementu
  do listy w miejsce wskazane przez priorytet.
*/
template <typename T>
void queue<T>::insert(T liczba, int prio)
{
    count++;
    node *v;
    node *r;
    v       = new node;
    v->data = liczba;
    v->prio = prio;
    v->next = NULL;
    v->prev = NULL;
    if(!head)
    {
        head = tail = v;
    }
    else if(head->prio > prio)
    {
        v->next    = head;
        head->prev = v;
        head       = v;
    }
    else
    {
        r = head;
        while((r->next) && (r->next->prio <= prio)) r = r->next;
        if(r->next)
            r->next->prev = v;
        v->next = r->next;
        r->next = v;
        v->prev = r;

        if(!v->next)
            tail = v;
    }
}


/*
  funkcja odpowiedzialna za wstawienie elementu na poczatek listy.
*/
template <typename T>
void queue<T>::push_front(T liczba, int prio)
{
    count++;
    node *v;
    v       = new node;
    v->data = liczba;
    v->prio = prio;
    v->next = NULL;
    v->prev = NULL;
    if(!head)
        head = tail = v;
    else
    {
        v->next    = head;
        head->prev = v;
        head       = v;
    }
}


/*
  funkcja odpowiedzialna za wstawienie elementu na poczatek listy.
*/
template <typename T>
void queue<T>::push_back(T liczba, int prio)
{
    count++;
    node *v;
    v       = new node;
    v->data = liczba;
    v->prio = prio;
    v->next = NULL;
    v->prev = NULL;
    if(!tail)
        tail = head = v;
    else
    {
        v->prev    = tail;
        tail->next = v;
        tail       = v;
    }
}


/*
funkcja odpowiedzialna za usuwanie wezla z listy
*/
template <typename T>
typename queue<T>::node *queue<T>::dequeue(node *e)
{
    if(isEmpty())
    {
        cout << "PUSTA!" << endl;
        Sleep(1500);
        return 0;
    }
    else
    {
        node *c = e;
        count--;
        if(e->prev)
            e->prev->next = e->next;
        else
            head = e->next;
        if(e->next)
            e->next->prev = e->prev;
        else
            tail = e->prev;
        delete e;
        return c;
    }
}

/*
  funkcja sprawdzajaca czy lista jest pusta
*/
template <typename T>
bool queue<T>::isEmpty(void)
{
    return count == 0 ? true : false;
}

/*
  funkcja obliczajaca rozmiar listy
*/
template <typename T>
int queue<T>::size(void)
{
    return count;
}

/*
  funkcja zwraca oraz zdejmuje element z konca listy
*/
template <typename T>
typename queue<T>::node *queue<T>::pop_back()
{
    return dequeue(tail);
}

/*
  funkcja zwraca oraz zdejmuje element z poczatku listy
*/
template <typename T>
typename queue<T>::node *queue<T>::removeMin()
{
    return dequeue(head);
}

/*
  funckja wypisuje na ekranie zawartosc kolejki priorytetowej
*/
template <typename T>
void queue<T>::printk()
{
    node *l;
    l = head;
    cout << "Zawartosc kolejki - " << count << " : [ ";
    while(l)
    {
        cout << "[" << l->prio << ", " << l->data << "]"
             << ", ";
        l = l->next;
    }
    cout << "] " << endl;
}

/*
  funckja wypisuje na ekranie zawartosc listy
*/
template <typename T>
void queue<T>::printl()
{
    node *l;
    l = head;
    cout << "Zawartosc listy - " << count << " : [ ";
    while(l)
    {
        cout << "[" << l->prio << ", " << l->data << "]"
             << ", ";
        l = l->next;
    }
    cout << "] " << endl;
}

/*
  funkcja zwraca element o indeksie podanym jako wejscie
*/
template<typename T>
typename queue<T>::node * queue<T>::atIndex(int index)
{
    node * v;
    v = head;
    for(int i = 1; i < index; i++)
        v = v->next;
    return v;
}

/*
  funkcja daje dostep do priorytetu danego wezla
*/
template<typename T>
int queue<T>::getprio(int index)
{
    node * v;
    v = atIndex(index);
    return v->prio;

}

/*
  funkcja daje dostep do liczby danego wezla
*/
template<typename T>
T queue<T>::getdata(int index)
{
    node *v;
    v = atIndex(index);
    return v->data;
}

/*
  funkcja zwraca indeks szukanego elementu
*/
template<typename T>
int queue<T>::indexOf(T liczba, int prio)
{
    int index=1;
    node * v;
    v = head;
    while((prio != v->prio) && (v->next))
    {
        v = v->next;
        index++;
    }


        while((liczba != v->data) && (v->next) && (prio==v->prio))
        {
            v = v->next;
            index++;

        }
        if(v->prio==prio && v->data==liczba)
        return index;
        else return -1;


}
template class queue<int>;
template class queue<float>;

