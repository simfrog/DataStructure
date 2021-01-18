#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "AdjMatGraph.h"

#define INF 9999

class WGraph : public AdjMatGraph
{
public:
    WGraph() {}
    ~WGraph() {}

    bool hasEdge(int i, int j) { return (getEdge(i,j) < INF); }

    void insertEdge(int u, int v, int weight) {
        if(weight >= INF) { weight = INF; }
        setEdge(u, v, weight);
    }

    void load(string filename) {
        cout << filename << endl;
        ifstream ifs(filename);
        string line;
        getline(ifs, line);
        cout << line << endl;
        stringstream ls(line);
        int n;
        ls >> n;
        for(int i = 0; i < n; i++) {
            getline(ifs, line);
            string str;
            int val;
            stringstream ls(line);
            ls >> str;
            insertVertex(str);
            for(int j = 0; j < n; j++) {
                ls >> val;
                insertEdge(i, j, val);
            }
        }
        ifs.close();
    }
};