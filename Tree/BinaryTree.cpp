#include <iostream>
#include "BinaryNode.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree tree;

    BinaryNode* d = new BinaryNode(4, nullptr, nullptr);
    BinaryNode* e = new BinaryNode(5, nullptr, nullptr);
    BinaryNode* b = new BinaryNode(2, d, e );
    BinaryNode* f = new BinaryNode(6, nullptr, nullptr);
    BinaryNode* c = new BinaryNode(3, f, nullptr);
    BinaryNode* a = new BinaryNode(1, b, c );
    tree.setRoot(a);

    cout << " 전체노드의 수: " << tree.getCount() << "\n";
    cout << " 단말노드의 수: " << tree.getLeafCount() << "\n";
    cout << " 이진트리 높이: " << tree.getHeight() << "\n";

    tree.inorder();
    cout << "\n";
    tree.preorder();
    cout << "\n";
    tree.postorder();
    cout << "\n";
    tree.levelorder();
    cout << "\n";

    BinaryTree tree2;

    BinaryNode* n1 = new BinaryNode (3 , nullptr, nullptr);
    BinaryNode* n2 = new BinaryNode (2 , nullptr, nullptr);
    BinaryNode* n3 = new BinaryNode ('*', n1, n2 );
    BinaryNode* n4 = new BinaryNode (5 , nullptr, nullptr);
    BinaryNode* n5 = new BinaryNode (6 , nullptr, nullptr);
    BinaryNode* n6 = new BinaryNode ('-', n4, n5);
    BinaryNode* n7 = new BinaryNode ('+', n3, n6);
    tree2.setRoot(n7);

    cout << "계산 결과: " << tree2.evaluate() << "\n\n";

    BinaryTree tree3;

    BinaryNode *m4 = new BinaryNode (200, nullptr, nullptr);
    BinaryNode *m5 = new BinaryNode (500, nullptr, nullptr);
    BinaryNode *m3 = new BinaryNode (100, m4, m5);
    BinaryNode *m2 = new BinaryNode (50, nullptr, nullptr);
    BinaryNode *m1 = new BinaryNode (0, m2, m3);
    tree3.setRoot(m1);

    cout << "용량 계산 결과: " << tree.calcSize() << "\n";

    return 0;
}