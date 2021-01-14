#pragma once
#include "AdjListGraph.h"
#include "CircularQueue.h"
using namespace std;

class SrchALGraph : public AdjListGraph 
{
protected:
    bool visited[MAX_VTXS];

public:
    void resetVisited() {
        for(int i = 0; i < size; i++) {
            visited[i] = false;
        }
    }

    /* 그 노드의 정점 번호가 v이면 u번째 정점과 v번째 정점이 인접 */
    bool isLinked(int u, int v) {
        for(Node* p = adj[u]; p != nullptr; p = p->getLink())
            if(p->getId() == v) { return true; }
        return false;
    }

    /* DFS */
    void DFS(int v) {
        visited[v] = true;
        cout << getVertex(v) << " ";
        for(Node* p = adj[v]; p != nullptr; p = p->getLink()) {
            if(visited[p->getId()] == false)
                DFS(p->getId());
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
            for(Node* w = adj[v]; w != nullptr; w = w->getLink()) {
                int id = w->getId();
                if(!visited[id]) {
                    visited[id] = true;
                    cout << getVertex(id) << " ";
                    que.enqueue(id);
                }
            }
        }
    }
};