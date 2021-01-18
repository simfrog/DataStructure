#pragma once
#include <iostream>
#include "OLinkedList.h"
#include "WGraph.h"
#include "VertexSets.h"
using namespace std;

class WGraphMST : public WGraph
{
public:
    /* kruskal의 최소 비용 신장 트리 프로그램 */
    void Kruskal() {
        o_linked_list o_edgelist;
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                if(hasEdge(i, j)) {
                    o_edgelist.orderedInsert(new node(getEdge(i,j),i,j));
                }
            }
        }

        VertexSets set(size);                       /* size개의 집합 만듬 */
        int edgeAccepted = 0;                       /* 선택된 간선 수 */
        while(edgeAccepted < size-1) {
            node* e = o_edgelist.getHead();         /* 최소 힙에서 삭제 */
            int uset = set.findSet(e->getSource()); /* 정점 u의 집합 번호 */
            int vset = set.findSet(e->getTarget()); /* 정점 v의 집합 번호 */
            if(uset != vset) {
                cout << "An edge added to MST: " << getVertex(e->getSource());
                cout << " " << getVertex(e->getTarget()) << " " << e->getWeight() << "\n";
                set.unionSets(uset, vset);
                edgeAccepted++;
            }
            o_edgelist.removeHead();
        }
    }

    /* Prim의 최소 비용 신장 트리 프로그램 */
    void Prim() {
        bool selected[MAX_VTXS];        /* 정점이 이미 포함되었는지? */
        int dist[MAX_VTXS];             /* 거리 */
        int source_vertex[MAX_VTXS];
        for(int i = 0; i < size; i++) {
            dist[i] = INF;
            selected[i] = false;
            source_vertex[i] = 0;
        }

        dist[0] = 0;

        for(int i = 0; i < size; i++) {
            int u = getMinVertex(selected, dist);   /* 포함되지 않은 정점들 중, MST와의 거리가 최소인 정점 */
            selected[u] = true;
            if(dist[u] >= INF) { return; }
            if(u != source_vertex[u]) {
                cout << "An edge added to MST: " << getVertex(u) << " ";
                cout << getVertex(source_vertex[u]) << " " << getEdge(u, source_vertex[u]) << "\n";
            }
            /* 새 MST부터 노드들의 거리를 업데이트 */
            for(int v = 0; v < size; v++) {
                if(getEdge(u,v) != INF) {
                    if(!selected[v] && getEdge(u,v) < dist[v]) {
                        dist[v] = getEdge(u,v);
                        source_vertex[v] = u;
                    }
                }
            }
        }
        cout << "\n";
    }

    /* MST에 포함되지 않은 정점들 중에서 MST와의 거리가 최소인 정점 선택 */
    int getMinVertex(bool* selected, int* dist) {
        int minv = 0;
        int mindist = INF;
        for(int v = 0; v < size; v++) {
            if(!selected[v] & dist[v] < mindist) {
                mindist = dist[v];
                minv = v;
            }
        }
        return minv;
    }
};