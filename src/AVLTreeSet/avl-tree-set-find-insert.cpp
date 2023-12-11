#include "INHA_OSAP_003_noogabar/header/AVLTreeSet/avl-tree-set.h"

// 담당자: 김예진

/**
 * @brief
 *
 * @tparam T
 * @param arg key 값
 * @return int depth 반환, 없을 시 0 반환
 * @tparam T
 * @param arg
 * @return int
 */
template <typename T>
int AVLTreeSet<T>::Find(T arg)
{

  /*
  avl-tree-set original 함수에 search 함수 있으니까 해당 함수 활용하시면 될 것
  같습니다.
  */
  Node *curN = this.getroot();
  int depth = 0;
  while (curN != nullptr)
  { // tree의 맨 하단까지 내려가며 있는지 확인
    if (arg == curN.getkey())
      return depth;
    curN = (arg > curN.getkey()) ? curN.getright() : curN.getleft();
    depth++;
  }
  return 0;
}

/**
 * @brief
 *
 * @param arg
 * @return int
 */
template <typename T>
int AVLTreeSet<T>::Insert(T arg)
{
  Node *curN = this.getroot();
  if (Find(arg) > 0 || arg == curN.key())
  {
    return -1;
  }

  Node *newN = new Node<T>(arg);
  Node *parN = nullptr;
  Node *grandparN = nullptr;

  if (curN == nullptr)
  {
    this.setroot(arg);
    return 0;
  }

  while (curN != nullptr)
  { // tree의 맨 하단까지 내려가며 있는지 확인
    if (arg > curN.getkey())
    {
      grandparN = parN;
      parN = curN;
      curN = curN.getright();
    }
    else
    {
      grandparN = parN;
      parN = curN;
      curN = curN.getleft();
    }
  }

  if (arg > parN.getKey())
  {
    parN.setright(newN);
  }
  else
  {
    parN.setleft(newN);
  }

  Balancing(grandparN);

  return Find(arg);
}

//====================기타 구현 함수====================