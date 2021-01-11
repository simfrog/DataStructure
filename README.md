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
### 2-1. 개념
#### 공집합이거나
#### 루트와 왼쪽 서브트리, 오른쪽 서브트리로 구성된 노드들의 유한 집합
#### 서브트리들은 모두 이진트리
### 2-2. 성질
1. n개의 노드를 가진 트리는 n-1개의 간선을 가진다.
2. 높이가 h인 이진트리는 h개 이상 2^h-1개 이하의 노드를 가진다.  
    레벨 i에서 노드의 최대 개수 : 2^(i-1)  
    시그마(i=1~h)s^(i-1) = 2^(h-1)
3. 이진트리의 높이는 log2(n+1) 이상 n 이하.  
    최소한 하나의 노드는 있어야 하므로 높이가 n을 넘을 수는 없다.  
    이진트리가 가질 수 있는 노드의 최댓값은 2^(h-1)  
    n <= 2^(h-1) -> 양변에 log를 취함 -> h >= log2(n+1)  
### 2-3. 종류
![트리종류](https://user-images.githubusercontent.com/31130917/104200441-03b00300-546c-11eb-9708-6c5584a4d083.png)

<출처 : https://limkydev.tistory.com/134>  
####
* #### 포화 이진트리(full binary tree) : 각 레벨에 노드가 꽉 차있는 이진트리
* #### 완전 이진트리(complete binary tree) : 높이가 k인 트리에서 레벨 1부터 k-1까지는 노드가 모두 채워져 있고 마지막 레벨 k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진트리  
    노드가 꽉 차 있지 않아도 된다. 하지만 중간에 빈곳이 있으면 안 된다.
    #### => 포화 이진트리는 완전 이진트리이지만 그 역은 항상 성립하지 않는다.
### 2-4. 추상 자료형
    데이터 : 노드와 간선의 집합. 노드는 공집합 또는 공집합이 아닌 경우  
            루트 노드와 왼쪽 서브트리, 오른쪽 서브트리로 구성.  
            이때 모든 서브트리도 이진트리.  
    연산 :  
        * create() : 이진트리 생성  
        * isEmpty() : 이진트리가 공백 상태인지 확인  
        * getRoot() : 이진트리의 루트 노드를 반환  
        * getCount() : 이진트리의 노드 수 반환  
        * getHeight() : 이진트리의 높이 반환  
        * insertNode(n) : 이진트리에 노드 n을 삽입  
        * deleteNode(n) : 이진트리에서 노드 n을 삭제  
        * display() : 이진트리의 내용을 화면에 출력
## 3. 표현
### 3-1. 배열 표현법
![배열표현법](https://user-images.githubusercontent.com/31130917/104202727-9fdb0980-546e-11eb-9b2b-77ffd9169037.png)

<출처 : https://medium.com/quantum-ant/%ED%8A%B8%EB%A6%AC-tree-cec69cfddb14>  
기억공간의 낭비가 심할 수 있다.  
### 3-2. 링크 표현법  
![링크표현법](https://user-images.githubusercontent.com/31130917/104203083-12e48000-546f-11eb-96e6-8573637598cf.png)

<출처 : https://colomy.tistory.com/72>  
## 4. 링크 표현법을 이용한 이진트리 구현  
![스크린샷(2)](https://user-images.githubusercontent.com/31130917/104204914-1da01480-5471-11eb-89c1-ed0a20aacac7.png)
## 5. 순회(traversal)
* #### 전위 순회(preorder) : 루트 -> 왼쪽 서브트리 -> 오른쪽 서브트리
'''  
preorder(x)

    if x != NULL  
        then print DATA(x);  
             preorder(LEFT(X));  
             preorder(RIGHT(X));  
'''
* #### 중위 순회(inorder) : 왼쪽 서브트리 -> 루트 -> 오른쪽 서브트리
* #### 후위 순회(postorder) : 왼쪽 서브트리 -> 오른쪽 서브트리 -> 루트
