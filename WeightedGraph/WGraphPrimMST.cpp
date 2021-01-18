#include "WGraphMST.h"
#include <iostream>
using namespace std;

int main() 
{
    WGraphMST g;
    g.load("graph.txt");
    g.display();

    cout << "\nMST By Kruskal's Algorithm\n";
    g.Kruskal();

    cout << "\nMST By Prim's Algorithm\n";
    g.Prim();

    return 0;
}