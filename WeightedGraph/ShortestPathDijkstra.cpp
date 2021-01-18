#include "WGraphDijkstra.h"
using namespace std;

int main()
{
    WGraphDijksra g;

    g.load("graph_sp.txt");
    cout << "File loaded\n";
    g.display();

    cout << "\nShortest Path By Dijkstra Algorithm\n";
    g.ShortestPath(0);
    cout << "\nFinding completed\n";
    for(int i = 0; i < 7; i++) {
        g.PrintPath(0, i);
    }

    for(int j = 0; j < 7; j++) {
        g.ShortestPath(j);
        cout << "\nFinding completed\n";
        for(int i = 0; i < 7; i++) {
            g.PrintPath(j, i);
        }
    }

    return 0;
}