#include <iostream>
#include "ConnectedComponentGraph.h"
using namespace std;

int main()
{
    ConnectedComponentGraph g;

    for(int i = 0; i < 5; i++)  {
        g.insertVertex(string(1, 'A'+i));
    }
    g.insertEdge(1,0);
    g.insertEdge(2,0);
    g.insertEdge(3,4);

    g.store("graph3.txt");
    g.display();

    g.resetVisited();
    g.findConnedtedComponent();

    return 0;
}