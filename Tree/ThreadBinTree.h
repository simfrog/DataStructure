#pragma once
#include <iostream>
using namespace std;

class ThreadBinNode
{
protected:
    int data;
    ThreadBinNode* left;
    ThreadBinNode* right;

public:
    bool bThread;
    ThreadBinNode(int val = 0, ThreadBinNode* l = nullptr, 
                ThreadBinNode* r = nullptr, bool bTh = false)
                :data(val), left(l), right(r), bThread(bTh) {}

    int getData() { return data; }
    void setRight(ThreadBinNode* r) { right = r; }
    ThreadBinNode* getLeft() { return left; }
    ThreadBinNode* getRight() { return right; }
};

class ThreadBinTree
{
private:
    ThreadBinNode* root;

public:
    ThreadBinTree(): root(nullptr) {}
    ~ThreadBinTree() {}

    void setRoot(ThreadBinNode* node) { root = node; }
    ThreadBinNode* getRoot() { return root; }
    bool isEmpty() { return root == nullptr; }

    void threadInorder() {
        if(!isEmpty()) {
            cout << "스레드 이진트리 중위순회: ";
            ThreadBinNode* q = root;
            while(q->getLeft()) {   /* 가장 왼쪽 노드로 이동 */
                q = q->getLeft();
            }

            do {
                cout << " [" << q->getData() << "] ";
                q = findSuccessor(q);   /* 후속자 호출 */
            } while(q);
            cout << "\n";
        }
    }

    ThreadBinNode* findSuccessor(ThreadBinNode* p) {
        ThreadBinNode* q = p->getRight();           /* 오른쪽 자식 포인터 저장 */
        if(q==nullptr || p->bThread) { return q; }  /* 오른쪽 자식이 nullptr 이거나 스레드이면 오른쪽 포인터를 반환 */
        while(q->getLeft() != nullptr) {            /* 오른쪽 자식이 존재하면 다시 가장 왼쪽 노드로 이동 */
            q = q->getLeft();
        }
        return q;
    }
};