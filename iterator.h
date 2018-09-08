#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    protected:
        Node<T>* current;

    public:
        Iterator() : current(nullptr) {};
        Iterator(Node<T>* current) : current(current) {};

        Iterator<T> operator=(Iterator<T> other) {
            current->data = other.current->data;
            current->next = other.current->next;

            return *this;
        };
        bool operator!=(Iterator<T> other) {
            return current->data == other.current->data;
        }
        T operator*() {
            return current->data;
        }
};

#endif
