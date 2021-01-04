#pragma once
#include <iostream>
using namespace std;

inline void error(const char* str) {
    cerr << str << "\n";
    exit(1);
};

class DArrayList
{
private:
    int *data;
    size_t length;
    size_t current_size;
    size_t resize_unit;

public:
    DArrayList(size_t init_size = 10) {
        cout << "\n<Initialize to: " << init_size << "> ";
        data = new int[init_size];
        current_size = init_size;
        resize_unit = init_size;
        length = 0;
    }
    ~DArrayList() { delete [] data; }

    void resize(size_t newsize) {
        int *temparray = new int[newsize];
        cout << "\n<Resize to: " << newsize << "> ";
        for(int i = 0; i < length; i++)
            temparray[i] = data[i];
        delete [] data;
        current_size = newsize;
        data = temparray;
    }

    void insert(int pos, int e) {
        if(pos >= 0 && pos <= length) {
            if(isFull()) resize(current_size+resize_unit);
            for(int i = pos+1; i < length; i++)
                data[i-1] = data[i];
            length--;
        } else {
            error ("포화상태 오류 또는 삽입 위치 오류\n");
        }
    }

    void remove(int pos) {
        if(!isEmpty() && 0 <= pos && pos < length) {
            if(current_size > resize_unit + length)
                resize(current_size-resize_unit);
            for(int i = pos+1; i < length; i++)
                data[i-1] = data[i];
            length--;
        } else {
            error ("공백상태 오류 또는 삽입 위치 오류\n");
        }
    }

    int size() { return length; }
    int getEntry(int pos) { return data[pos]; }
    bool isEmpty() { return length == 0; }
    bool isFull() { return length == current_size; }

    bool find(int item) {
        for(int i = 0; i < length; i++)
            if(data[i] == item) { return true; }
        return false;
    }

    void replace(int pos, int e) {
        if(!isEmpty() && 0 <= pos && pos < length) {
            data[pos] = e;
        } else {
            cout << "공백상태 오류 또는 치환 위치 오류\n";
        }
    }

    void display() {
        cout << "Array List의 총 항목 수: " << length;
        for(int i = 0; i < length; i++)
            cout << "[" << data[i] << "]";
        cout << "\n";
    }

    void clear() {
        length = 0;
        resize(resize_unit);
    }
};