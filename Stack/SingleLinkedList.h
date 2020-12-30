#pragma once
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

struct node 
{
    int data;
    node *next;
};

class s_linked_list
{
protected:
    node *head, *tail;
    int size = 0;

public:
    s_linked_list() {
        head = nullptr;
        tail = nullptr;
    }
    ~s_linked_list() {
        delete_list();
    }

    void push_front(int n);
    void push_back(int n);
    void insert_node_at(int idx, int n);

    int pop_front();
    int pop_back();
    int pop_node_at(int idx);
    void remove_node(int n);
    void delete_list();

    void replace_value_at(int idx, int n);

    int Size();
    void display_contents();
    int search_value(int n);
};

void s_linked_list::push_front(int n) {
    node *ptr = new node;
    ptr->next = head;
    ptr->data = n;
    head = ptr;
    if(ptr->next == nullptr) { tail = ptr; }
    size++;
}

void s_linked_list::push_back(int n) {
    node *tmp = new node;
    tmp->data = n;
    tmp->next = nullptr;
    if(head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
    size++;
}

void s_linked_list::insert_node_at(int idx, int n) {
    if(size < idx || 0 > idx) {
        cout << "해당 인덱스는 존재하지 않습니다.\n";
    } else if(idx == 0) {
        push_front(n);
    } else if(idx == size) {
        push_back(n);
    } else {
        node *ptr = head;
        node *tmp = ptr;
        node *new_node = new node;
        new_node->data = n;
        new_node->next = nullptr;
        for(int i = 0; i < idx; i++) {
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = new_node;
        new_node->next = ptr;
        size++;
    }
}

int s_linked_list::pop_front() {
    if(head == nullptr) {
        cout << "linked list가 비어있습니다.\n";
        exit(1);
    }
    node *ptr = head;
    int value = head->data;
    head = ptr->next;
    if(head == nullptr) { tail == nullptr; }
    delete ptr;
    size--;
    return value;
}

int s_linked_list::pop_back() {
    if(size == 0) {
        cout << "linked list가 비어있습니다.\n";
        exit(1);
    }
    node *ptr = head;
    node* tmp = new node;
    while(ptr->next != nullptr) {
        tmp = ptr;
        ptr = ptr->next;
    }
    int value = ptr->data;
    if(ptr == head) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tmp;
        tail->next = nullptr;
    }
    delete ptr;
    size--;
    return value;
}

int s_linked_list::pop_node_at(int idx) {
    int value = -1;
    if(size <= idx || 0 > idx) {
        cout << "해당 인덱스는 존재하지 않습니다.\n";
    } else if(size == 0) {
        cout << "linked list가 비어있습니다.\n";
        exit(1);
    } else if(idx == 0) {
        value = pop_front();
    } else {
        node *ptr = head;
        node *tmp = ptr;
        for(int i = 0; i < idx; i++) {
            tmp = ptr;
            ptr = ptr->next;
        }
        value = ptr->data;
        tmp->next = ptr->next;
        if(ptr == tail) { tail = tmp; }
        size--;
        delete ptr;
        ptr = nullptr;
    }
    return value;
}

void s_linked_list::remove_node(int n) {
    node *ptr = head;
    node *tmp = ptr;
    while(ptr != nullptr) {
        if(ptr->data == n) { break; }
        else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if(ptr == nullptr) {
        cout << "값의 노드는 존재하지 않습니다.\n";
    } else if(size == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        size--;
        cout << ptr->data << "값의 노드를 하나 지웁니다.\n";
        tmp->next = ptr->next;
        if(ptr == tail) { tail = tmp; }
        delete ptr;
    }
}

void s_linked_list::delete_list() {
    node *ptr = head;
    while(ptr != nullptr) {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    cout << "리스트가 삭제되었습니다.\n";
}

void s_linked_list::replace_value_at(int idx, int n) {
    node *ptr = head;
    if(size == 0) {
        cout << "linked list가 비어있습니다.\n";
        exit(1);
    } else if(size <= idx || 0 > idx) {
        cout << "해당 인덱스는 존재하지 않습니다.\n";
    } else {
        for(int i = 0; i < idx; i++) {
            ptr = ptr->next;
        }
        ptr->data = n;
    }
}

int s_linked_list::Size() {
    return size;
}

void s_linked_list::display_contents() {
    node *ptr = head;
    while(ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "nullptr" << "\n";
}

int s_linked_list::search_value(int n) {
    node *ptr = head;
    int idx = 0;
    bool isFind = false;
    while(ptr != nullptr) {
        if(ptr->data == n) {
            cout << n << " 은 " << idx << " 에 있습니다.\n";
            isFind = true;
            break;
        }
        ptr = ptr->next;
        idx++;
    }
    if(isFind == false) {
        cout << n << " 은 리스트 안에 없습니다.\n";
        return -1;
    } else { return idx; }
}