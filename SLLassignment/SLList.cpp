#ifndef SLLIST_CPP
#define SLLIST_CPP

#include "SLList.hpp"
#include <iostream>

template <typename T>
SLList<T>::SLList() : head(nullptr), list_size(0) {}

template <typename T>
unsigned SLList<T>::size() const {
    return list_size;
}

template <typename T>
bool SLList<T>::empty() const {
    return (size() == 0);
}

template <typename T>
void SLList<T>::push_front(const T& val) {
    SLLNode<T>* new_node = new SLLNode<T>(val);
    new_node->next = head;
    head = new_node;
    list_size++;
}

template <typename T>
void SLList<T>::print() const {
    std::cout << "{ ";
    SLLNode<T>* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << " }";
}

template <typename T>
void SLList<T>::insert(unsigned pos, const T& value, unsigned n) {
    if (pos > size()) return;
    if (pos == 0) {
        for (unsigned i = 0; i < n; i++) {
            SLLNode<T>* new_node = new SLLNode<T>(value);
            new_node->next = head;
            head = new_node;
        }
        list_size += n;
        return;
    }
    SLLNode<T>* prev = head;
    for (unsigned i = 0; i < pos - 1; i++) {
        prev = prev->next;
    }
    for (unsigned i = 0; i < n; i++) {
        SLLNode<T>* new_node = new SLLNode<T>(value);
        new_node->next = prev->next;
        prev->next = new_node;
        prev = new_node;
    }
    list_size++;
}

template <typename T>
void SLList<T>::push_back(const T& val) {
    insert(size(), val, 1);
}

template <typename T>
void SLList<T>::erase(unsigned pos) {
    if (pos >= size()) return;
    if (pos == 0) {
        SLLNode<T>* to_delete = head;
        head = head->next;
        delete to_delete;
        list_size--;
        return;
    }
    SLLNode<T>* prev = head;
    for (unsigned i = 0; i < pos - 1; i++) {
        prev = prev->next;
    }
    SLLNode<T>* to_delete = prev->next;
    prev->next = to_delete->next;
    delete to_delete;
    list_size--;
}

template <typename T>
void SLList<T>::remove(const T& value) {
    while (head != nullptr && head->data == value) {
        SLLNode<T>* to_delete = head;
        head = head->next;
        delete to_delete;
        list_size--;
    }
    if (head == nullptr) return;  

    SLLNode<T>* prev = head;
    SLLNode<T>* cur = head->next;
    while (cur != nullptr) {
        if (cur->data == value) {
            prev->next = cur->next;   
            delete cur;
            list_size--;
            cur = prev->next;    
        } else {
            prev = cur;            
            cur = cur->next;
        }
    }
}


#endif