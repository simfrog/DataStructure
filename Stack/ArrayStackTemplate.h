#pragma once
#include <iostream>
#include <typeinfo>
#include "Student.h"
using namespace std;

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
    cerr << str << "\n";
    exit(1);
}

template <typename T>
class ArrayStack
{
    T data[MAX_STACK_SIZE]; 
    int top;

public:
    ArrayStack() { top = -1; }
    ~ArrayStack(){}
    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX_STACK_SIZE-1; }

    void push(T e){
        if(isFull()) error ("스택 포화 에러");
        data[++top] = e;
    }

    T pop(){
        if( isEmpty() ) error ("스택 공백 에러");
        return data[top--];
    }

    T peek(){
        if( isEmpty() ) error ("스택 공백 에러");
        return data[top];
    }

    void display(){ 
        cout << "[스택 항목의 수 = " << top+1 << "] \n";
        for (int i=0 ; i<=top ; i++)
            cout << "<" << data[i] << ">";
        cout << "\n";       
    }
};