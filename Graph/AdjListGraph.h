#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define MAX_VTXS 256

class Node
{
protected:
    int id;
    Node* link;

public:
    Node(int i, Node* l = nullptr) : id(i), link(l) {}
    ~Node() {
        if(link != nullptr) { delete link; }
    }

    int getId() { return id; }
    Node* getLink() { return link; }
    void setLink(Node* l) { link = l; }
};

class AdjListGraph
{
protected:
    int size;
    string vertices[MAX_VTXS];  /* Vertex의 정보 */
    Node* adj[MAX_VTXS];        /* 각 Vertex의 인접 리스트 */

public:
    AdjListGraph() : size(0) {}
    ~AdjListGraph() { reset(); }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }
    string getVertex(int i) { return vertices[i]; }

    void reset() {
        for(int i = 0; i < size; i++) {
            if(adj != nullptr) { delete adj[i]; }
        }
        size = 0;
    }

    void insertVertex(string val) {
        if(!isFull()) {
            vertices[size] = val;
            adj[size++] = nullptr;
        } else {
            cout << "Exceeding maxinum number of vertices\n";
        }
    }

    void insertEdge(int u, int v) {
        if(adj[u] == nullptr) {
            adj[u] = new Node(v, adj[u]);
        } else {
            Node *p = adj[u];
            while(p->getLink() != nullptr) {
                p = p->getLink();
            }
            p->setLink(new Node(v, nullptr));
        }
    }

    void display() {
        cout << size << "\n";
        for(int i = 0; i < size; i++) {
            cout << getVertex(i) << " ";
            for(Node* v = adj[i]; v != nullptr; v = v->getLink()) {
                cout << getVertex(v->getId()) << " ";
            }
            cout << "\n";
        }
    }

    void load(string filename) {
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
                if(val != 0) { insertEdge(i, j); }
            }
        }
        ifs.close();
    }
};