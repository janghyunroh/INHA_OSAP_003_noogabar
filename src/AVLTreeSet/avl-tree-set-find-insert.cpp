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
  // 비어있는 tree인지 확인 후, 비어있으면 root로 삽입
  if (Size() == 0)
  {
    this.setroot(arg);
    return 0;
  }

  Node *parN = this.getroot();
  // arg의 값을 갖는 노드가 이미 존재하는지 확인
  if (Find(arg) > 0 || arg == parN.key())
  {
    return -1;
  }

  Insert_N(parN, arg);
  return Find(arg);
}

//====================기타 구현 함수====================

template <typename T>
void AVLTreeSet<T>::Insert_N(Node<T> *parN, T arg)
{
  if (parN->get_key > arg)
  {
    if (parN->get_left() == nullptr)
    {
      Node *newN = new Node<T>(arg);
      parN->set_left(newN);
      return;
    }
    else
    {
      Insert_N(parN->get_left(), arg);
      Balancing(parN);
    }
  }
  else
  {
    if (parN->get_right() == nullptr)
    {
      Node *newN = new Node<T>(arg);
      parN->set_right(newN);
      return;
    }
    else
    {
      Insert_N(parN->get_right(), arg);
      Balancing(parN);
    }
  }
  return;
}