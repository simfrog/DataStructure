#pragma once
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template<typename T>
struct node
{
    T data;
    node<T> *next = nullptr;
    node<T> *prev = nullptr;
};

template <typename T>
class d_linked_list
{
protected:
    node<T> *head, *tail;
    int length = 0;

public:
    d_linked_list() {
        head = nullptr;
        tail = nullptr;
    }    
    ~d_linked_list() {
        delete_list();
    }

    void push_front(T n);
    void push_back(T n);
    void insert_node_at(int idx, T n);

    T pop_front();
    T pop_back();
    T pop_node_at(int idx);
    void delete_list();

    T front();
    T back();
    int size();
    void display_contents();
};

template<typename T>
void d_linked_list<T>::push_front(T n) {
    node<T> *ptr = new node<T>;
    ptr->data = n;
    ptr->next = head;
    if(head == nullptr) {
        head = ptr;
        tail = ptr;
    } else {
        head->prev = ptr;
        head = head->prev;
    }
    length++;
}

template<typename T>
void d_linked_list<T>::push_back(T n) {
    node<T> *tmp = new node<T>;
    tmp->data = n;
    tmp->prev = tail;
    if(head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
    length++;
}

template<typename T>
void d_linked_list<T>::insert_node_at(int idx, T n) {
    if(length < idx || 0 > idx) {
        cout << "해당 인덱스는 존재하지 않습니다.\n";
    } else if(idx <= length/2) {
        node<T> *new_node = new node<T>;
        new_node->data = n;
        node<T> *ptr = head;
        if(idx == 0) {
            push_front(n);
        } else {
            for(int i = 0; i < idx; i++) {
                ptr = ptr->next;
            }
            new_node->next = ptr; /* N -> B, A <-> B */
            if(ptr != nullptr) {
                new_node->prev = ptr->prev; /* A <- N -> B, A <-> B */
                ptr->prev = new_node;       /* A <- N <-> B, A -> B */
                if(new_node->prev != nullptr)
                    new_node->prev->next = new_node; /* A <-> N <-> B */
            }
            length++;
        }
    } else {
        node<T> *new_node = new node<T>;
        new_node->data = n;
        node<T> *tmp = tail;
        for(int i = 0; i < (length-idx); i++) {
            tmp = tmp->prev;
        }
        if(tmp == tail) {
            push_back(n);
        } else {
            new_node->prev = tmp;       /* A <- N, A -> B */
            new_node->next = tmp->next; /* A <- N -> B */ 
            tmp->next = new_node;       /* A <-> N -> B */
            if(new_node->next != nullptr) {
                new_node->next->prev = new_node; /* A <-> N <-> B */
            }
            length++;
        }
    }
}

template<typename T>
T d_linked_list<T>::pop_front() { 
    if(length <= 0 ) {
        cout << "Linked List가 비어있습니다.\n";
    } else {
        node<T> *ptr = head; 
        T value = head->data; 
        head = ptr->next;
        if(head == nullptr) {
            tail = nullptr;
        } else { 
            head->prev = nullptr; 
        }
        delete ptr;
        length--;
        return value;
    }
}

template<typename T>
T d_linked_list<T>::pop_back() {
    if(length <= 0) {
        cout << "Linked List가 비어있습니다.\n";
    } else {
        node<T> *tmp = tail;
        T value = tail->data;
        tail = tmp->prev;
        if(tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete tmp;
        length--;
        return value;
    }
}

template<typename T>
T d_linked_list<T>::pop_node_at(int idx) {
    T value;
    if(length < idx || 0 > idx) {
        cout << "해당 인덱스는 존재하지 않습니다.\n";
    } else if(idx <= length/2) {
        if(idx == 0) {
            return pop_front();
        } else {
            node<T> *ptr = head;
            for(int i = 0; i < idx; i++) {
                ptr = ptr->next;
            }
            if(ptr == tail) {
                return pop_back();
            }
            value = ptr->data;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            length--;
            delete ptr;
        }
    } else {
        node<T> *tmp = tail;
        for(int i = 0; i < (length-idx); i++) {
            tmp = tmp->prev;
        }
        if(tmp == tail) {
            return pop_back();
        } else {
            value = tmp->data;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            length--;
            delete tmp;
        }
    }
    return value;
}

template<typename T>
void d_linked_list<T>::delete_list() {
    node<T> *ptr = head;
    while(ptr != nullptr) {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    length = 0;
    cout << "리스트가 삭제되었습니다.\n";
}

template<typename T>
int d_linked_list<T>::size() {
    return length;
}

template<typename T>
T d_linked_list<T>::front() {
    if(length <= 0) {
        cout << "Linked List가 비어있습니다.\n";
    } else {
        return head->data;
    }
}

template<typename T>
T d_linked_list<T>::back() {
    if(length <= 0) {
        cout << "Linked List가 비어있습니다.\n";
    } else {
        return tail->data;
    }
}

template<typename T>
void d_linked_list<T>::display_contents() {
    node<T> *ptr = head;
    cout << "From head: nullptr->";
    while(ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "nullptr" << "\n";

    ptr = tail;
    cout << "From tail: nullptr->";
    while(ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->prev;
    }
    cout << "nullptr" << "\n";
}

template<typename T>
class dll_deque: public d_linked_list<T>
{
public:
    dll_deque() : d_linked_list<T>(){}
    ~dll_deque(){this->delete_list();}
    using d_linked_list<T>::push_front; // 방법 1
    void addFront(T n){push_front(n);}
    void addRear(T n){d_linked_list<T>::push_back(n);} // 방법 2
    T getFront(){return this->front();} // 방법 3
    T getRear(){return d_linked_list<T>::back();}
    T deleteFront(){return this->pop_front();}
    T deleteRear(){return d_linked_list<T>::pop_back();}       
};