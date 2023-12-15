
#class Node
##데이터 멤버

T key
: 노드에 저장 되어있는 실제 데이터. 과제에서 이야기하는 key와 동일 

~~int depth~~deprecated

**고려 사항 - depth 데이터 멤버의 필요성 여부**
 depth 데이터 멤버를 사용하게 되면 특정 노드의 depth를 따로 계산할 필요 없이 즉각 lookup할 수 있어 여러 함수들이 꽤 빨라지게 된다(시간 복잡도는 동일). 그러나 AVL Tree의 balancing 과정에서 이 depth를 무결성이 깨지지 않도록 적절히 변경해주어야 한다는 점에서 추가적인 구현 비용이 들어간다. 
 depth 데이터 멤버를 사용하지 않는다면 height함수를 통해 구한 height값과 root의 height값의 차를 이용하여 depth를 구할 수 있지만 이렇게 한다면 log n의 시간 소모가 추가된다. 

**결론적으로 depth 데이터 멤버는 구현하지 않기로 결정됨**
AVL Tree는 기본적으로 하위 노드부터 재귀적으로 각종 필드를 갱신하기 때문에, 상위 노드에 의해 재귀적으로 정의되는 depth 데이터는 유지하는 것이 의미가 없다.
대신 height 필드를 추가하여 balancing의 수행 시간이 O(log n)이 보장되도록 하였다. 

Node* left_
: 왼쪽 자식 노드

Node* right_
: 오른쪽 자식 노드

int height
: balancing을 O(log n) 시간 내에 수행하기 위한 데이터 필드

int sub_size
: rank를 O(log n) 시간 내에 수행하기 위한 데이터 필드


##멤버 메서드 
– 각 데이터 멤버에 대한 getter와 setter
- 생성자
**주의 사항** 
key에 대한 setter는 delete 함수에서 후임자의 key를 복사하기 위해 어쩔 수 없이 구현했으며,
이외의 경우엔 사용하지 않는 것이 좋음. 


#class Set
##데이터 멤버
unsigned int size_
: Set의 크기. 

##멤버 메서드
###순수 가상 함수
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

###추가로 필요한 함수
int get_size()
: size_에 대한 getter

void IncreaseSize()
: size_ 1 증가

void DecreaseSize()
: size_ 1 감소


#class TreeSet : public Set
##데이터 멤버
Node* root
: TreeSet의 root 노드. 

##멤버 메서드
root의 getter와 setter
생성자


#class AVL Tree
##데이터 멤버
~~Node * root~~deprecated
root는 tree의 공통 요소이므로 tree class에서 구현하도록 하였습니다. 


##멤버 메서드

Set class의 가상함수 구현

###AVL Tree를 위한 기본적인 함수
Node* RR(Node* node)
: node를 z 노드로 하는 right rotation

Node* LL(Node* node)
: node를 z 노드로 하는 left rotation

Node* RL(Node* node)
: node를 z 노드로 하는 right-left rotation

Node* LR(Node* node)
: node를 z 노드로 하는 left-right rotation

Height node	
: 입력된 노드의 왼쪽 자식의 height와 오른쪽 자식의 height 중 큰 것 + 1을 반환

HeightDiff node 
: 왼쪽 자식 height – 오른쪽 자식 height. balancing 과정에 사용됨

Balancing node 
: heightDiff 함수 호출로 좌우 차이 1 넘는지 확인 후 적절한 로테이션 연산 수행

Search node 
: root에서부터 값 비교해가며 내려가기. 없으면 Null pointer 반환

int UpdateHeight(Node* node)
: node의 갱신할 height를 구해주는 함수. 실질적인 갱신은 rotation 내에서 대입을 통해 이루어진다. 

int UpdateSubSize(Node* node)
: node의 갱신할 sub tree size를 구해주는 함수. 실질적인 갱신은 rotation 내에서 대입을 통해 이루어진다. 

###구현해야 할 Set의 함수

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

###추가적으로 필요한 함수

Node* InsertRecursive
: Insert 내에서 실질적인 삽입과 balancing을 수행하는 재귀 함수 

Node* Delete
: Erase 내에서 실질적인 삭제와 balancing을 수행하는 재귀 함수





