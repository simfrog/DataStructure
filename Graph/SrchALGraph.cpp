#include <iostream>
#include "SrchALGraph.h"
using namespace std;

int main()
{
    SrchALGraph g;
    g.load("graph2.txt");
    cout << "그래프를 불러왔습니다.\n";
    g.display();

    cout << "DFS ==> ";
    g.resetVisited();
    g.DFS(0);
    cout << "\n";

    cout << "BFS ==> ";
    g.resetVisited();
    g.BFS(0);
    cout << "\n";

    return 0;
}