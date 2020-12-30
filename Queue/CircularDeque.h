#pragma once
#include "CircularQueue.h"

class CircularDeque: public CircularQueue
{
public:
    CircularDeque() {}
    void addRear(int val) { enqueue(val); }
    int deleteFront() { return dequeue(); }
    int getFront() { return peek(); }
    void addFront(int val) {
        if(isFull()) error ("Error: 덱이 포화상태입니다.\n");
        else {
            data[front] = val;
            front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
    }
    int deleteRear() {
        if(isEmpty()) error ("Error: 덱이 공백상태입니다.\n");
        else {
            int ret = data[rear];
            rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }
    int getRear() {
        if(isEmpty()) error ("Error: 덱이 공백상태입니다.\n");
        else return data[rear];
    }
    void display() {
        cout << "Deque 안에는: ";
        int maxi = (front < rear)? rear : rear+MAX_QUEUE_SIZE;
        for(int i = front+1; i <= maxi; i++) {
            cout << data[i%MAX_QUEUE_SIZE] << " ";
        }
        cout << "\n";
    }
};