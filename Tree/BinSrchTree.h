#pragma once
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class BinSrchTree : public BinaryTree
{
public:
    BinSrchTree() {}
    ~BinSrchTree() {}

    BinaryNode* search(int key) {
        BinaryNode* node = search(root, key);
        if(node != nullptr) {
            cout << "탐색 성공. Key: " << key;
            cout << "노드: " << node->getData();
        } else {
            cout << "탐색 실패. Key: " << key;
        }
        return node;
    }

    BinaryNode* search(BinaryNode* n, int key) {
        if(n == nullptr) { return nullptr; }
        if(key == n->getData()) { 
            return n;
        } else if(key < n->getData()) {
            return search(n->getLeft(), key);
        } else {
            return search(n->getRight(), key);
        }
    }

    void insert(BinaryNode* n) {
        if(n == nullptr) { return; }
        if(isEmpty()) {
            root = n;
        } else {
            insert(root, n);
        }
    }

    void insert(BinaryNode* r, BinaryNode* n) {
        if(n->getData() == r->getData()) { 
            return; 
        } else if(n->getData() < r->getData()) {
            if(r->getLeft() == nullptr) {
                r->setLeft(n);
            } else {
                insert(r->getLeft(), n);
            }
        } else {
            if(r->getRight() == nullptr) {
                r->setRight(n);
            } else {
                insert(r->getRight(), n);
            }
        }
    }

    void remove(int data) {
        if(isEmpty()) { return; }
        
        BinaryNode* parent = nullptr;
        BinaryNode* node = root;

        while(node != nullptr && node->getData() != data) {
            parent = node;
            node = (data < node->getData())? node->getLeft() : node->getRight(); 
        }

        if(node == nullptr) {
            cout << "Key " << data << " does not exist";
            return;
        } else {
            remove(parent, node);
        }
    }

    void remove(BinaryNode* parent, BinaryNode* node) {
        /* 삭제 노드가 단말 노드일 경우 */
        if(node->isLeaf()) {
            if(parent == nullptr) {
                root = nullptr;
            } else {
                if(parent->getLeft() == node) {
                    parent->setLeft(nullptr);
                } else {
                    parent->setRight(nullptr);
                }
            } /* 삭제 노드가 하나의 서브트리만 가지고 있는 경우 */
        } else if(node->getLeft() == nullptr || node->getRight() == nullptr) {
            BinaryNode* child = (node->getLeft() != nullptr)
                                ? node->getLeft()
                                : node->getRight();
            
            if(node == root) {
                root = child;
            } else {
                if(parent->getLeft() == node) {
                    parent->setLeft(child);
                } else {
                    parent->setRight(child);
                }
            } /* 양쪽 서브트리가 다 있는 경우 */
        } else {
            BinaryNode* succp = node;               /* 계승자 바로 위 부모 노드 */
            BinaryNode* succ = node->getRight();    /* 계승자 노드 */

            while(succ->getLeft() != nullptr) {
                succp = succ;
                succ = succ->getLeft();
            }

            /* 오른쪽 트리에서 가장 작은 노드를 찾음 */
            if(succp->getLeft() == succ) {
                succp->setLeft(succ->getRight());
            }
            /* 오른쪽 트리에서 가장 작은 노드가 왼쪽 노드일 때 */
            /* 계승자 부모의 왼쪽 노드를 계승자의 오른쪽 자식 노드로 정해줌 */
            else {
                succp->setRight(succ->getRight());
            }
            /* 오른쪽 트리에서 가장 작은 노드가 오른쪽 노드일 때 */
            /* 계승자 부모의 오른쪽 노드를 계승자의 오른쪽 자식 노드로 정해줌 */
            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }
};