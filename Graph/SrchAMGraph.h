#pragma once
#include <iostream>
#include "AdjMatGraph.h"
#include "CircularQueue.h"
using namespace std;

class SrchAMGraph : public AdjMatGraph
{
protected:
    bool visited[MAX_VTXS];

public:
    void resetVisited() {
        for(int i = 0; i < size; i++)
            visited[i] = false;
    }

    /* u번째 정점과 v번째 정점이 연결되어 있는지 검사 */
    bool isLinked(int u, int v) {
        return getEdge(u,v) != 0;
    }

    /* DFS */
    void DFS(int v) {
        visited[v] = true;
        cout << getVertex(v) << " ";
        
        for(int w = 0; w < size; w++) {
            if(isLinked(v,w) && visited[w]==false)
                DFS(w);
        }
    }

    /* BFS */
    void BFS(int v) {
        visited[v] = true;
        cout << getVertex(v) << " ";
        CircularQueue que;
        que.enqueue(v);
        
        while(!que.isEmpty()) {
            int v = que.dequeue();
            for(int w = 0; w < size; w++) {
                if(isLinked(v,w) && visited[w]==false) {
                    visited[w] = true;
                    cout << getVertex(w) << " ";
                    que.enqueue(w);
                }
            }
        }
    }
};