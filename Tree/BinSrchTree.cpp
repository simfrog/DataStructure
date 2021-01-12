#include "BinSrchTree.h"
using namespace std;

int main()
{
    BinSrchTree tree;

    tree.insert(new BinaryNode(35));
    tree.insert(new BinaryNode(18));
    tree.insert(new BinaryNode(7));
    tree.insert(new BinaryNode(26));
    tree.insert(new BinaryNode(12));
    tree.insert(new BinaryNode(3));
    tree.insert(new BinaryNode(68));
    tree.insert(new BinaryNode(22));
    tree.insert(new BinaryNode(30));
    tree.insert(new BinaryNode(99));

    cout << "노드의 수: " << tree.getCount() << "\n";
    cout << "단말의 수: " << tree.getLeafCount() << "\n";
    cout << "트리의 높이: " << tree.getHeight() << "\n";

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    tree.search(26);
    tree.search(25);

    cout << "\n\n삭제 case 1: 노드 3 삭제 \n";
    tree.remove(3);
    tree.inorder();
    cout << "삭제 case 2: 노드 68 삭제 \n";
    tree.remove(68);
    tree.inorder();
    cout << "삭제 case 3: 노드 18 삭제 \n";
    tree.remove(18);
    tree.inorder();
    cout << "삭제 case 3: 노드 35 (루트 노드) 삭제 \n";
    tree.remove(35);
    tree.inorder();

    cout << "노드의 수: " << tree.getCount() << "\n";
    cout << "단말의 수: " << tree.getLeafCount() << "\n";
    cout << "트리의 높이: " << tree.getHeight() << "\n";

    return 0;
}