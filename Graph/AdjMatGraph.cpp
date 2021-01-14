#include <string>
#include <iostream>
#include "AdjMatGraph.h"
using namespace std;

int main()
{
    AdjMatGraph g;

    for(int i = 0; i < 4; i++) {
        g.insertVertex(string(1, 'A'+i));
    }
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    g.insertEdge(1,3);
    g.insertEdge(2,3);
    g.display();
    g.store("graph1.txt");
    cout << "Graph saved\n";
    g.reset();
    cout << "Graph reset\n";
    g.load("graph1.txt");
    cout << "Graph loaded\n";
    g.display();

    return 0;
}