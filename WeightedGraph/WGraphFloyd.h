#pragma once
#include "WGraph.h"
using namespace std;

class WGraphFloyd : public WGraph
{
protected:
    int A[MAX_VTXS][MAX_VTXS]; /* 최단경로 거리 */
    int path[MAX_VTXS][MAX_VTXS];

public:
    void ShortestPathFloyd() {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                A[i][j] = getEdge(i, j);
                path[i][j] = j;
            }
        }

        for(int k = 0; k < size; k++) {
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    if(A[i][k] + A[k][j] < A[i][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                        path[i][j] = path[i][k];
                    }
                }
            }
            printA();
        }
    }

    void PrintPath(int start, int end) {
        cout << "Shortest path " << getVertex(start) << "->" << getVertex(end) << ": ";
        cout << getVertex(start);
        while(path[start][end] != end) {
            cout << "-" << getVertex(path[start][end]);
            start = path[start][end];
        }
        cout << "-" << getVertex(end) << "\n";
    }

    void printA() {
        cout << "Shortest path length matrix\n";
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(A[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << A[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
};