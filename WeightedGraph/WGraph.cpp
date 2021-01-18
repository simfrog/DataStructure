#include "WGraph.h"
using namespace std;

int main()
{
    WGraph g;
    g.load("graph.txt");
    g.display();

    return 0;
}