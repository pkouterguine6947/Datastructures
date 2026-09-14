#include "SLList.hpp"
#include <iostream>

int main() {
    SLList<char> l;

    l.push_back('a');
    l.push_back('b');
    l.push_back('a');
    l.push_back('a');
    l.push_back('c');
    l.push_back('d');
    l.push_back('a');
    l.print();
    l.remove('a');
    l.print();
}