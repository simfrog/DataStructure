#pragma once
#include "AdjListGraph.h"
#include "ArrayStack.h"
using namespace std;

class TopoSortGraph : public AdjListGraph
{
public:
    TopoSortGraph() {}
    ~TopoSortGraph() {}

    /* u->v의 방향성 있는 간선을 만듬 */
    void insertDirEdge(int u, int v) {
        adj[u] = new Node(v,adj[u]);
    }

    void TopoSort() {
        ArrayStack s;
        int *inDeg = new int [size];    /* 모든 정점의 in-degree를 구함 */

        for(int i = 0; i < size; i++) { /* in-degree 초기화 */
            inDeg[i] = 0;
        }

        for(int i = 0; i <size; i++) {
            Node* node = adj[i];        /* 정점 i에서 나오는 간선들 */
            while(node != nullptr) {
                inDeg[node->getId()]++;
                node = node->getLink();
            }
        }

        /* in-degree가 0인 정점(위상 정렬에서 처음 나오는 정점)들을 stack에 삽입 */
        for(int i = 0; i < size; i++) {
            if(inDeg[i] == 0) { s.push(i); }
        }

        while(s.isEmpty() == false) {
            int w = s.pop();
            cout << getVertex(w) << " ";
            Node* node = adj[w];
            while(node != nullptr) {
                int u = node->getId();             /* seed 정점의 이웃 정점에 대해 연산 수행 */
                inDeg[u]--;                        /* 그 노드들의 in-degree 하나씩 줄여줌 */
                if(inDeg[u] == 0) { s.push(u); }   /* 0이 되면 stack에 삽입 */
                node = node->getLink();            /* 다음 이웃 조회 */
            }
        }
        cout << "\n";
        delete [] inDeg;
    }
};