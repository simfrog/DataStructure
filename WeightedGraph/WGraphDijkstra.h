#pragma once
#include "WGraph.h"
#include <iostream>
using namespace std;

class WGraphDijksra :  public WGraph 
{
protected:
    int path[MAX_VTXS];
    int dist[MAX_VTXS];     /* 시작노드로부터 최단경로 거리 */
    bool found[MAX_VTXS];   /* 방분한 정점 표시 */

public:
    WGraphDijksra() {}
    ~WGraphDijksra() {}

    void PrintDistance() {
        for(int i = 0; i < size; i++)
            cout << dist[i] << " ";
    }

    void PrintPath(int start, int end) {
        cout << "Shortest path " << getVertex(end) << "->" << getVertex(start) << ": ";
        cout << getVertex(end);
        while(path[end] != start) {
            cout << "-" << getVertex(path[end]);
            end = path[end];
        }
        cout << "-" << getVertex(start) << "\n";
    }

    /* 방문하지 정점들 중 최단경로 거리가 가장 작은 정점을 찾아 반환 */
    int chooseVertex() {
        int min = INF;
        int minpos = -1;
        for(int i = 0; i < size; i++) {
            if(dist[i] < min && !found[i]) {
                min = dist[i];
                minpos = i;
            }
        }
        return minpos;
    }

    /* Dijkstra의 최단 경로 알고리즘 */
    void ShortestPath(int start) {
        /* 초기화 */
        for(int i = 0; i < size; i++) {
            dist[i] = getEdge(start, i);
            path[i] = start;
            found[i] = false;
        }
        found[start] = true;    /* 시작노드 방문 표시 */
        dist[start] = 0;        /* 최초 거리 */

        for(int i = 0; i < size; i++) {
            cout << "STEP " << i+1 << " ";
            PrintDistance();
            int u = chooseVertex();
            found[u] = true;
            for(int w = 0; w < size; w++) {
                if(!found[w]) {
                    if(dist[u] + getEdge(u,w) < dist[w]) {
                        dist[w] = dist[u] + getEdge(u,w);
                        path[w] = u;
                    }
                }
            }
            cout << "\n";
        }
    }
};