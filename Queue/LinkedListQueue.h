#pragma once
#include "SingleLinkedList.h"
using namespace std;

inline void error(const char* str) {
    cerr << str << "\n";
    exit(1);
};

class LinkedListQueue : public s_linked_list 
{
public:
    LinkedListQueue(): s_linked_list() {}
    bool isEmpty() { return Size() == 0; }
    void enqueue(int e) { push_back(e); }

    int dequeue() {
        if(isEmpty()) error ("Queue 공백 에러");
        return pop_front();
    }

    int peek() {
        if(isEmpty()) error ("Queue 공백 에러");
        return head->data;
    }

    void display() {
        cout << "Qeueue 안에는: ";
        node* ptr = head;
        for(int i = 0; i < Size(); i++) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
};