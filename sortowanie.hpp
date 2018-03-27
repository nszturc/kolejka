#ifndef SORTOWANIE_HPP
#define SORTOWANIE_HPP
#include "kolejka.hpp"

template <typename T>
class sorting : public queue<T>
{
public:
    void insert(queue<T> *lista);
    void selection(queue<T> *lista);
};
#endif // SORTOWANIE_HPP
