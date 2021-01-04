#pragma once
#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node* next;

public:
    node(int val = 0) {
        data = val;
        next = nullptr;
    }

    node* getLink() { return next; }
    int getData() { return data; }
    void setLink(node* target) { next = target; }

    void insertNext(node *newnode) {
        if(newnode != nullptr) {
            newnode->next = next;
            next = newnode;
        }
    }

    node* removeNext() {
        node* removed = next;
        if(removed != nullptr)
            next = removed->next;
        return removed;
    }
};

class hn_s_linked_list
{
protected:
    node origin;

public:
    hn_s_linked_list() : origin(0) {}
    ~hn_s_linked_list() { clear(); }

    void clear();
    node* getHead();
    bool isEmpty();

    node* getEntry(int pos);
    void insert(int pos, node* n);
    void remove(int pos);
    node* find(int value);
    void replace(int pos, node* n);
    size_t size();
    void display();
};

void hn_s_linked_list::clear() {
    while(!isEmpty()) {
        remove(0);
    }
}

node* hn_s_linked_list::getHead() {
    return origin.getLink();
}

bool hn_s_linked_list::isEmpty() {
    return getHead() == nullptr;
}

node* hn_s_linked_list::getEntry(int pos) {
    node* n = &origin;
    for(int i = -1; i < pos; i++, n = n->getLink()) {
        if(n == nullptr) { break; }
    }
    return n;
}

void hn_s_linked_list::insert(int pos, node* n) {
    node* prev = getEntry(pos-1);
    if(prev != nullptr) {
        prev->insertNext(n);
    }
}

void hn_s_linked_list::remove(int pos) {
    node* prev = getEntry(pos-1);
    delete prev->removeNext();
}

node* hn_s_linked_list::find(int value) {
    for(node* p = getHead(); p != nullptr; p = p->getLink()) {
        if(p->getData() == value) { return p; }
    }
    return nullptr;
}

void hn_s_linked_list::replace(int pos, node* n) {
    node* prev = getEntry(pos-1);
    if(prev != nullptr) {
        delete prev->removeNext();
        prev->insertNext(n);
    }
}

size_t hn_s_linked_list::size() {
    int count = 0;
    for(node* p = getHead(); p != nullptr; p = p->getLink()) {
        count++;
    }
    return count;
}

void hn_s_linked_list::display() {
    cout << "전체 항목의 수: " << size() << ", ";
    for(node* p = getHead(); p != nullptr; p = p->getLink()) {
        cout << p->getData() << " ";
    }
}