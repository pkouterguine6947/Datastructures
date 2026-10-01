#ifndef SLLIST_HPP
#define SLLIST_HPP

#include "SLLNode.hpp"

template <typename T>
class SLList {
public:
    SLList();

    unsigned size() const;
    bool     empty() const;

    void push_front(const T& val);
    void push_back(const T& val);
    void insert(unsigned pos, const T& value, unsigned n = 1);
    void erase(unsigned pos);
    void remove(const T& value);

    void print() const;

private:
    SLLNode<T>* head;
    unsigned    list_size;
};

#include "SLList.cpp"

#endif