#pragma once
#include "HeapNode.h"
using namespace std;

#define MAX_ELEMENT 200

class MinHeap
{
protected:
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MinHeap() : size(0) {}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT-1; }

    HeapNode& getParent(int i) { return node[i/2]; }
    HeapNode& getLeft(int i) { return node[i*2]; }
    HeapNode& getRight(int i) { return node[i*2+1]; }

    void insert(int key) {
        if(isFull()) { return; }
        int i = ++size;

        while(i != 1 && key < getParent(i).getKey()) {
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key);
    }

    HeapNode remove() {
        if(isEmpty()) { return NULL; }
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;

        while(child <= size) {
            if(child<size && getLeft(parent).getKey()>getRight(parent).getKey())
                child++;
            if(last.getKey() <= node[child].getKey())
                break;
            /* 아니면 한 단계 아래로 이동 */
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
    }
};