#ifndef KOLEJKA_HPP
#define KOLEJKA_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
class queue
{
protected:
    struct node
    {
        node *next;
        node *prev;
        T prio;
        T data;
    };
    node *head;
    node *tail;
    int count;

public:
    queue()
    {
        head = tail = NULL;
        count       = 0;
    }
    ~queue()
    {
        while(count) removeMin();
    }
    void push_front(T liczba, T prio);
    void push_back(T liczba, T prio);
    node *dequeue(node *e);
    node *pop_back();
    node *removeMin();
    T min(void) { return head->data; }
    int size(void);
    bool isEmpty(void);
    void printk(void);
    void printl(void);
    void insert(T liczba, T prio);
    T getprio(int index);
    int getcount(void) { return count; }
    node * atIndex(int index);
    T getdata(int index);
    int indexOf(T liczba, T prio);
};
#endif // KOLEJKA_HPP
