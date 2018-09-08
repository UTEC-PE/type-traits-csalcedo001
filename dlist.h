#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator <T> () {};
        DListIterator(Node <T> *current) : Iterator <T> (current) {};
        DListIterator <T> operator++() {
            if (this->current)
                this->current = this->current->next;

            return *this;
        }
        DListIterator <T> operator--() {
          if (this->current)
              this->current = this->current->prev;

          return *this;
        }
};

template <typename Tr>
class DList {
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;

    private:
        Node <T> *head;
        Node <T> *tail;

    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            if (!head) {
                head = tail = new Node <T> (data);
                return;
            }

            Node <T> *tmp = new Node <T> (data);

            tmp->next = head;
            tmp->next->prev = tmp;
            head = tmp;
        }

        void push_back(T data) {
            if (!tail) {
                head = tail = new Node <T> (data);
                return;
            }

            Node <T> *tmp = new Node <T> (data);

            tmp->prev = tail;
            tmp->prev->next = tmp;
            tail = tmp;
        }

        void pop_front() {
            if (!head)
                return;

            if (!head->next) {
                delete head;
                return;
            }

            Node <T> *tmp = head;

            head = head->next;
            head->prev = nullptr;

            delete tmp;
        }

        void pop_back() {
            if (!tail)
                return;

            if (!tail->prev) {
                delete tail;
                return;
            }

            Node <T> *tmp = tail;

            tail = tail->prev;
            tail->next = nullptr;

            delete tmp;
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator();
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
