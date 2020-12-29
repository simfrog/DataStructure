#pragma once
#include <iostream>
#include "Student.h"

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
    cerr << str << "\n";
    exit(1);
}

class StudentStack
{
private:
    int top;
    Student data[MAX_STACK_SIZE];

public:
    StudentStack() { top = -1; }
    ~StudentStack() {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE-1; }

    void push(Student e) {
        if(isFull()) error ("스택 포화 에러");
        data[++top] = e;
    }

    Student pop() {
        if(isEmpty()) error ("스택 공백 에러");
        return data[top--];
    }

    Student peek() {
        if(isEmpty()) error ("스택 공백 에러");
        return data[top];
    }

    void display() {
        cout << "[전체 학생의 수 = " << top+1 << "]\n";
        for(int i = 0; i <= top; i++)
            cout << i << " <" << data[i].contents() << ">\n";
        cout << "\n";
    }
};