#pragma once
#include <iostream>
using namespace std;

#define INF 9999

/* singly linked list 구현 */
class node 
{
private:
    int weight;
    int v1, v2;
    node* next;

public:
    node(int val = INF, int vx1 = -1, int vx2 = -1) {
        weight = val;
        v1 = vx1;
        v2 = vx2;
        next = nullptr;
    }
    ~node() {}

    node* getLink() { return next; }
    int getWeight() { return weight; }
    int getSource() { return v1; }
    int getTarget() { return v2; }
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

class o_linked_list
{
protected:
    node origin;

public:
    o_linked_list() {}
    ~o_linked_list() { clear(); }

    void clear() {
        while(!isEmpty()) {
            origin.removeNext();
        }
    }

    bool isEmpty() {
        return getHead() == nullptr;
    }

    node* getHead() {
        return origin.getLink();
    }

    void removeHead() {
        origin.removeNext();
    }

    void orderedInsert(node* n) {
        int w = n->getWeight();
        node* prev = &origin;
        node* now = getHead();
        while(now != nullptr) {
            int now_w = now->getWeight();
            if(now_w >= w) {
                prev->insertNext(n);
                return;
            }
            prev = now;
            now = now->getLink();
        }
        prev->insertNext(n);
    }

    size_t size() {
        int count = 0;
        for(node *p = getHead(); p != nullptr; p = p->getLink()) {
            count++;
        }
        return count;
    }

    void display() {
        cout << "전체 항목의 수: " << size() << "\n";
        for(node *p = getHead(); p != nullptr; p = p->getLink()) {
            cout << p->getWeight() << " " << p->getSource() << " " << p->getTarget() << "\n";
        }
    }
};