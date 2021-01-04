#include "HnSLinkedList.h"

int main()
{
    hn_s_linked_list list;

    list.insert(0, new node(10));
    list.insert(0, new node(20));
    list.insert(1, new node(30));
    list.insert(list.size(), new node(40));
    list.insert(2, new node(50));
    list.display();

    list.remove(2);
    list.remove(list.size()-1);
    list.remove(0);
    list.replace(1, new node(90));
    list.display();

    list.clear();
    list.display();
    return 0;
}