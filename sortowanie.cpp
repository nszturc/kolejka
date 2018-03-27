#include "sortowanie.hpp"
#include "kolejka.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

/*
  funkcja odpowiedzialna za sortowanie przez wstawianie
*/
template <typename T>
void sorting<T>::insert(queue<T> *list)
{
    queue<T> kolejka;
    typename queue<T>::node *v;
    while(!list->isEmpty())
    {

        //list->printl();
        //kolejka.printk();
        v = list->removeMin();
        kolejka.insert(v->data, v->prio);
       // cout << endl;
        //Sleep(500);
    }
    while(!kolejka.isEmpty())
    {
        //list->printl();
       // kolejka.printk();
        v = kolejka.removeMin();
        list->push_back(v->data, v->prio);
       // cout << endl;
       // Sleep(500);
    }
}

/*
  funckja odpowiedzialna za sortowanie przez wybieranie
*/
template <typename T>
void sorting<T>::selection(queue<T> *list)
{
    queue<T> kolejka;
    typename queue<T>::node *v;
    while(!list->isEmpty())
    {
       // list->printl();
       // kolejka.printk();
        v = list->removeMin();
        kolejka.push_back(v->data, v->prio);
       // cout << endl;
        //Sleep(500);
    }
    while(!kolejka.isEmpty())
    {
       // list->printl();
       // kolejka.printk();
        v = kolejka.removeMin();
        list->insert(v->data, v->prio);
       // cout << endl;
        //Sleep(500);
    }
}
template class sorting<int>;
template class queue<float>;
