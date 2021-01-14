#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

# define MAX_VTXS 256

class AdjMatGraph
{
protected:
    int size;
    string vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];

public:
    AdjMatGraph(){ reset(); }
    ~AdjMatGraph(){}

    std::string getVertex(int i) { return vertices[i]; }
    int getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    void reset() {
        size = 0;
        for(int i = 0 ; i < MAX_VTXS ; i++) {
            for(int j = 0 ; j < MAX_VTXS ; j++) {
                setEdge(i,j,0);
            }
        }
    }

    void insertVertex(std::string name) {
        if(!isFull()) { vertices[size++] = name; }
        else { cout << "Exceeding maximum number of vertices"; } 
    }

    void insertEdge(int u, int v) {
        if(u < 0 || u >= size || u < 0 && u >= size) {
            cout << "out of range";
            exit(0);
        }
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    void display() {
        cout << size << "\n";
        for(int i = 0 ; i < size ; i++) {
            cout << getVertex(i) << "  ";
            for(int j = 0 ; j < size ; j++)  
                cout << getEdge(i, j) << " ";
            cout << "\n";
        }
    }

    void load(string filename) {
        ifstream ifs(filename);
        string line;
        getline(ifs, line);
        cout << line << std::endl;
        stringstream ls(line);
        int n;
        ls >> n;                        /* 정점의 전체 개수 */
        for(int i = 0; i < n; i++) {
            getline(ifs, line);
            string str;
            int val;
            stringstream ls(line);
            ls >> str;                  /* 정점의 이름 */
            insertVertex(str);
            for(int j = 0; j < n; j++) {
                ls >> val;              /* 간선 정보 */
                if(val != 0) {
                    insertEdge(i, j);
                }
            }
        }
        ifs.close();
    }

    void store(string filename) {
        ofstream ofs(filename);
        ofs << size << "\n";
        for(int i = 0 ; i < size ; i++) {
            ofs << getVertex(i) << "  ";
            for(int j = 0 ; j < size ; j++)  
                ofs << getEdge(i, j) << " ";
            ofs << "\n";
        }
        ofs.close();
    }
};