# INHA_OSAP_003_noogabar
AVL Tree 및 이를 활용한 Set STL 구현

## 프로젝트 소개
인하대학교 2023-2학기 오픈소스응용프로그래밍 수업의 팀 프로젝트입니다. 

## 개발 개요
### 개발 기간
2023/10/30 ~ 2023/12/15

### 멤버 구성 및 역할 분담
12191595 노장현
12191598 류지훈
12201776 이정현
1220 김예진



### 기타 사항
License: 
Style Guide: CSE3210
Code Format: clang-format

## 주요 기능
### 기본 기능
- minimum x

  노드 x가 root인 부분 트리 내에서 최소 key를 갖는 노드의 key와 depth 출력
  
- maximum x
  
  노드 x가 root인 부분 트리 내에서 최대 key를 갖는 노드의 key와 depth 출력
  
- empty
  
  set의 empty 여부 출력
  
- size
  
  set에 저장된 원소의 개수 출력
  
- find x
  
  노드 x의 depth 출력 (없을 시 0)
  
- insert x
  
  새로운 노드 x를 set에 삽입 후, 삽입된 위치의 depth 출력

### 고급 기능
- rank x
  
  노드 x의 depth와 rank를 출력
  rank = (전체 Set에서 x보다 작은 원소의 개수 + 1)
  
- erase x
  
  노드 x의 depth를 출력하고 노드 x 삭제
