#include "WGraphFloyd.h"
#include <iostream>
using namespace std;

int main()
{
    WGraphFloyd g;
    g.load("graph_sp.txt");
    g.display();
    cout << "\nShortest Path By Floyd Algorithm\n";
    g.ShortestPathFloyd();
    for(int i = 0; i < 7; i++) {
        g.PrintPath(0,i);
    }

    return 0;
}