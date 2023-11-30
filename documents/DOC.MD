
##class Node
데이터 멤버
T key
: 노드에 저장 되어있는 실제 데이터. 과제에서 이야기하는 key와 동일

~~int depth~~
~~: 노드의 tree에서의 depth~~   

**고려 사항 - depth 데이터 멤버의 필요성 여부**
 depth 데이터 멤버를 사용하게 되면 특정 노드의 depth를 따로 계산할 필요 없이 즉각 lookup할 수 있어 여러 함수들이 꽤 빨라지게 된다(시간 복잡도는 동일). 그러나 AVL Tree의 balancing 과정에서 이 depth를 무결성이 깨지지 않도록 적절히 변경해주어야 한다는 점에서 추가적인 구현 비용이 들어간다. 
 depth 데이터 멤버를 사용하지 않는다면 height함수를 통해 구한 height값과 root의 height값의 차를 이용하여 depth를 구할 수 있지만 이렇게 한다면 log n의 시간 소모가 추가된다. 

**결론적으로 depth 데이터 멤버는 구현하지 않기로 결정됨**

Node* left_
: 왼쪽 자식 노드

Node* right_
: 오른쪽 자식 노드

멤버 메서드 
– 각 데이터 멤버에 대한 getter와 setter
- 생성자


##class Set
데이터 멤버
unsigned int size_
: Set의 크기. 

멤버 메서드
T Maximum(T arg)
: 최대 키 반환

T Minimum(T arg)
: 최소 키 반환

bool Empty()
:empty 여부 반환

int Size()
: 크기 반환

int Find(T arg)
: 해당 노드 depth 반환

int Insert(T arg)
: arg로 새 노드 생성 후 삽입, 삽입 위치 depth 반환

int Rank(T arg)
: 해당 노드 rank 반환

int Erase(T arg)
: 해당 노드 삭제 후 삭제 전 depth 반환(없으면 0) 



##class TreeSet : public Set
데이터 멤버
Node* root
: TreeSet의 root 노드. 

멤버 메서드
root의 getter와 setter




##class AVL Tree
데이터 멤버
~~Node * root~~
~~: AVL Tree의 root 노드. Tree의 모든 접근은 root 노드를 통해서 이루어진다.~~

멤버 메서드

Set class의 가상함수 구현

<rotate 연산>
RR node	// O (1)
LL node	// O (1)
LR node	// O (1)
RL node	// O (1)


~~
Height node	// O (log n)
: 입력된 노드의 왼쪽 자식의 height와 오른쪽 자식의 height 중 큰 것 + 1을 반환(재귀)

HeightDiff node // log n + log n -> O (log n)
: 왼쪽 자식 height – 오른쪽 자식 height. balancing 과정에 사용됨

Balancing node // log n + c -> O (log n)
: heightDiff 함수 호출로 좌우 차이 1 넘는지 확인 후 적절한 로테이션 연산 수행

Insert X // log n + log n -> O (log n)
	: 대소 비교로 자리 찾기 + Tree balancing
	**추가 사항**
    이후 해당 노드의 depth를 반환하는 기능 추가할 것 ( Set – Insert 구현 위함)

Search node // O (log n)
	: root에서부터 값 비교해가며 내려가기. 없으면 Null pointer 반환

Erase X	// log n + log n OR log n
: Search X 수행 뒤 없으면 0반환, 있으면 해당 노드의 depth 출력하고 
	**고려 사항** 
depth 출력 때문에 굳이 Search 함수를 처음에 사용하는데, 만약 AVL Tree의 Erase 함수에 depth 반환 기능을 구현한다면 AVL Tree의 Erase 한번 호출로 해결 가능



##class Set
데이터 멤버

int size			
: AVL Tree의 크기. insert / delete시 증감

멤버 메서드
Minimum X	// log n + log n OR log n + log n + log n -> O (log n)
: AVL Tree에서 Search(x)를 통해 부분 트리의 root 노드를 찾은 뒤 거기서부터 Right-most Element로 traversal하여 해당 노드의 key와 depth를 pair로 반환

Maximum X	// log n + log n OR log n + log n + log n -> O (log n)
: AVL Tree에서 Search(X)를 통해 부분 트리의 root 노드를 찾은 뒤 거기서부터 Left-Most Element로 traversal하여 해당 노드의 key와 depth를 pair로 반환

Empty	// O (1)
: AVL Tree의 root 노드가 NULL인지 여부 반환 
or 	
클래스 자체의 Size 함수 써서 0인지 여부 반환


Size	// O (1)
: Set 클래스 자체에 데이터 멤버 Size를 사용하여 해당 값 반환

Find X // log n OR log n + log n -> O (log n)
: AVL Tree의 Search함수를 사용하여 반환된 pair의 depth 요소를 반환

Insert X // O (log n)
	: AVL Tree의 Insert함수를 통해 원소 삽입 및 depth 반환
**AVL Tree의 Insert에 depth 반환 기능 추가 예정

Erase X // O (log n)
	: AVL Tree의 Erase 사용하여 삭제 및 depth 반환
	**추후 AVL Tree의 Erase 기능 구현할 예정

Rank X // O (log n) (추정)
	: 추후 추가 예정
**아래 링크 참조하여 구현할 것 (필요에 따라 추가적인 함수 구현이 필요할 수 있음)
https://velog.io/@ehekaanldk/AVL-tree
https://stackoverflow.com/questions/5137741/how-to-find-the-rank-of-a-node-in-an-avl-tree

~~


