#ifndef SLLNODE_HPP
#define SLLNODE_HPP

template <typename T>
struct SLLNode {
    T data;
    SLLNode<T>* next;

    SLLNode(T d = T(), SLLNode<T>* n = nullptr)
        : data(d), next(n) {}
};

#endif