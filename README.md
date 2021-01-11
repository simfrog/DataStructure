# DataStructure

# 08.Tree

## 1. 개념
#### 계층적인 자료구조(hierachical data structure)
#### 한 개 이상의 노드로 이루어진 유한 집합
ex) 컴퓨터의 저장장치, 결정트리(decision tree)
####
### 1-1. 용어

![트리용어](https://user-images.githubusercontent.com/31130917/104160270-32aa8280-5434-11eb-89af-fd86ecde9e91.PNG)
####
* #### 노드(node) : 트리의 구성 요소   
    ex) A, B, C, D, E, F, G, H ,I ,J  
* #### 루트(root) : 트리에서 가장 높은 곳에 있는 노드
    ex) A  
* #### 서브트리(subtree) : 루트 노드를 제외한 나머지 노드
    ex) B, C, D, E, F, G, H ,I ,J  
    
    {B, E, F, G}, {C, H}, {D, I, J} -> A의 서브트리  
    {E}, {F}, {G} -> B의 서브트리  
* #### 간선(edge) : 루트와 서브트리를 잇는 연결선

![트리용어2](https://user-images.githubusercontent.com/31130917/104162557-2d4f3700-5438-11eb-88fc-242e843ad448.PNG)
####
* #### 부모 노드(parent node)  
    ex) A는 B의 부모 노드  
* #### 자식 노드(children node)  
    ex) B는 A의 자식 노드  
* #### 조상 노드(ancestor node) : 루트 노드에서 임의 노드까지의 경로를 이루고 있는 노드들  
* #### 자손 노드(descendent node) : 임의 노드 하위에 연결된 모든 노드들  
* #### 단말 노드(leaf node) : 자식 노드가 없는 노드  
* #### 차수(degree) : 어떤 노드가 가지고 있는 자식 노드의 개수  
* #### 레벨(level)  
* #### 트리의 높이(height) : 트리의 최대 레벨  
* #### 포레스트(forest) : 트리들의 집합  
####
## 2. 이진트리(Binary tree)
