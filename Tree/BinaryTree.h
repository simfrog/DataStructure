#pragma once
#include <iostream>
#include "BinaryNode.h"
#include "CircularQueue.h"
using namespace std;

class BinaryTree
{
protected:
    BinaryNode* root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {}

    void setRoot(BinaryNode* node) {
        root = node;
    }

    BinaryNode* getRoot() {
        return root;
    }

    bool isEmpty() {
        return root==nullptr;
    }

    /* 중위순회 (left->root->right) */
    void inorder(BinaryNode* node) {
        if(node != nullptr) {
            if(node->getLeft() != nullptr)
                inorder(node->getLeft());
            cout << " [" << node->getData() << "] ";
            if(node->getRight() != nullptr)
                inorder(node->getRight());
        }
    }

    void inorder() {
        cout << "inorder: ";
        inorder(root);
        cout << "\n";
    }

    /* 전위순회 (root->left->right) */
    void preorder(BinaryNode* node) {
        if(node != nullptr) {
            cout << " [" << node->getData() << "] ";
            if(node->getLeft() != nullptr)
                preorder(node->getLeft());
            if(node->getRight() != nullptr)
                preorder(node->getRight());
        }
    }

    void preorder() {
        cout << "preorder: ";
        preorder(root);
        cout << "\n";
    }

    /* 후위순회 (left->right->root) */
    void postorder(BinaryNode* node) {
        if(node != nullptr) {
            if(node->getLeft() != nullptr)
                postorder(node->getLeft());
            if(node->getRight() != nullptr)
                postorder(node->getRight());
            cout << " [" << node->getData() << "] ";
        }
    }

    void postorder() {
        cout << "postorder: ";
        postorder(root);
        cout << "\n";
    }

    /* 레벨순회 */
    void levelorder() {
        cout << "levelorder: ";
        if(!isEmpty()) {
            CircularQueue q;
            q.enqueue(root);
            while(!q.isEmpty()) {
                BinaryNode* n = q.dequeue();
                if(n != nullptr) {
                    cout << " [" << n->getData() << "] ";
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        cout << "\n";
    }

    /* 노드 개수 구하는 함수 */
    int getCount() {
        return isEmpty()? 0 : getCount(root);
    }

    int getCount(BinaryNode* node) {
        if(node == nullptr) { return 0; }
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }

    /* 단말 노드 개수 구하는 함수 */
    int getLeafCount() {
        return isEmpty()? 0 : getLeafCount(root);
    }

    int getLeafCount(BinaryNode* node) {
        if(node == nullptr) { return 0; }
        if(node->isLeaf()) { return 1; }
        else { return getLeafCount(node->getLeft()) + getLeafCount(node->getRight()); }
    }

    /* 이진트리의 높이 구하는 함수 */
    int getHeight() {
        return isEmpty()? 0 : getHeight(root);
    }

    int getHeight(BinaryNode* node) {
        if(node == nullptr) { return 0; }
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft>hRight)? hLeft+1 : hRight+1;
    }

    /* 디렉토리 용량 계산 */
    int calcSize() {
        return calcSize(root);
    }

    int calcSize(BinaryNode* node) {
        if(node == nullptr) { return 0; }
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
    }

    /* 수식 계산 */
    int evaluate() {
        return evaluate(root);
    }

    int evaluate(BinaryNode* node) {
        if(node == nullptr) { return 0; }
        if(node->isLeaf()) {
            return node->getData();
        } else {
            int op1 = evaluate(node->getLeft());
            int op2 = evaluate(node->getRight());
            switch(node->getData()) {
                case '+': return op1+op2;
                case '-': return op1-op2;
                case '*': return op1*op2;
                case '/': return op1/op2;
            }
            return 0;
        }
    }
};