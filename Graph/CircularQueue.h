#pragma once
#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
    cerr << str << "\n";
    exit(1);    
};

class CircularQueue
{
protected:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];

public:
    CircularQueue() { front = rear = 0; }
    ~CircularQueue() {}
    bool isEmpty() { return front == rear; }
    bool isFUll() { return (rear+1) % MAX_QUEUE_SIZE == front; }
    
    void enqueue(int val) {
        if(isFUll()) {
            error ("Error : 큐가 포화상태입니다.\n");
        } else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    int dequeue() {
        if(isEmpty()) {
            error ("Error : 큐가 공백상태입니다.\n");
        } else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};