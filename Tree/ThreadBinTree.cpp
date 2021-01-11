#include "ThreadBinTree.h"

int main()
{
    ThreadBinTree tree;

    ThreadBinNode* n1 = new ThreadBinNode (1, nullptr, nullptr, true);
	ThreadBinNode* n2 = new ThreadBinNode (2, nullptr, nullptr, true);
	ThreadBinNode* n3 = new ThreadBinNode (3, n1, n2, false);
	ThreadBinNode* n4 = new ThreadBinNode (4, nullptr, nullptr, true);
	ThreadBinNode* n5 = new ThreadBinNode (5, nullptr, nullptr, false);
	ThreadBinNode* n6 = new ThreadBinNode (6, n4, n5, false);
	ThreadBinNode* n7 = new ThreadBinNode (7, n3, n6, false);
	tree.setRoot(n7);

    n1->setRight(n3);
    n2->setRight(n7);
    n4->setRight(n6);

    tree.threadInorder();
    
    return 0;
}