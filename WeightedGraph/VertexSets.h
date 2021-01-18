/* 정점 집합들을 관리 */
class VertexSets
{
protected:
    int parent[MAX_VTXS];
    int size;

public:
    /* 초기에는 연결되어 있는 노드들이 없으므로, 모든 노드가 다 루트 */
    VertexSets(int nSets) {
        size = nSets;
        for(int i = 0; i < nSets; i++)
            parent[i] = -1;
    }

    bool IsRoot(int i) { return parent[i] < 0; }

    /* 주어진 노드의 루트(set의 대표노드)를 찾음 */
    int findSet(int vertex) {
        int id = vertex;
        while(!IsRoot(id)) {
            id = parent[id];
        }
        return id;
    }

    /* s1의 루트 노드를 s2로 정의 */
    void unionSets(int s1, int s2) {
        parent[s1] = s2;
        size--;
    }
};