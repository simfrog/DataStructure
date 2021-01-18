#include "WGraphMST.h"
#include <iostream>
using namespace std;

int main()
{
    WGraphMST g;
    g.load("graph.txt");
    g.display();

    cout << "MST By Kruskal's Algorithm\n";
    g.Kruskal();

    return 0;
}