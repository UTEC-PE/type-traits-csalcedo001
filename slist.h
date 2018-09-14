#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {
    public:
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++() {
            if (this->current)
                this->current = this->current->next;

            return *this;
        }
};

template <typename Tr>
class SList {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;

    private:
        Node <T> *head;
        Operation cmp;

    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            while (*pointer && !cmp(search, (*pointer)->data))
                pointer = &((*pointer)->next);

            return *pointer ? search == (*pointer)->data : false;
        }

        bool insert(T data) {
            if (!head) {
                head = new Node <T> (data); // No deberías tener tantos casos, se puede reducir bastante este insert. Hay lógica repetida
                return true;
            }

            Node <T> **nodeptr = &head;

            if (find(data, nodeptr))
                return false;

            Node <T> *tmp = new Node <T> (data);

            tmp->next = *nodeptr;
            *nodeptr = tmp;

            return true;
        }

        bool remove(T item) { // Tienes lógica repetida
            if (!head)
                return false; // There is no item to be removed

            Node <T> **nodeptr = &head;

            if (!find(item, nodeptr))
                return false; // There is no item to be removed

            if (!(*nodeptr)->next) {
                delete *nodeptr;
                *nodeptr = nullptr;

                return true;
            }

            Node <T> *tmp = *nodeptr;

            *nodeptr = (*nodeptr)->next;

            delete tmp;

            return true;
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator();
        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
