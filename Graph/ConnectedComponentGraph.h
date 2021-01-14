#pragma once
#include <iostream>
#include "SrchAMGraph.h"
using namespace std;

class ConnectedComponentGraph : public SrchAMGraph
{
protected:
    int label[MAX_VTXS];    /* 정점의 색상 필드 추가 */

public:
    void labelDFS(int v, int color) {
        visited[v] = true;
        label[v] = color;
        cout << getVertex(v) << " ";
        for(int w = 0; w < size; w++) {
            if(isLinked(v,w) && visited[w]==false)
                labelDFS(w,color);
        }
    }

    void findConnedtedComponent() {
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(visited[i] == false)
                labelDFS(i, ++count);
        }
        cout << "\nNumber of Connected Components: " << count << "\n";
        for(int i = 0; i < size; i++) {
            cout << getVertex(i) << ":" << label[i] << " ";
        }
        cout << "\n";
    }
};