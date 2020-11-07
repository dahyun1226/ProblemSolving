#include <iostream>
using namespace std;

class InvalidIndexException {};
template <typename T> class listNode {
public:
  T value;
  listNode<T> *next;

  listNode<T>() : next(nullptr) {}
  listNode<T>(T value1, listNode<T> *next1) : value(value1), next(next1) {}
};

template <typename T> class linkedList {
public:
  listNode<T> *head;
  int size;
  linkedList<T>() : size(0), head(nullptr) {}
  ~linkedList<T>() {
    listNode<T> *t1 = head, *t2;
    while (t1 != nullptr)
      t2 = t1->next;
  }

  void insert(int k, T value) {
    try {
      if (k < 0 || k > size) {
        throw InvalidIndexException();
      }
      if (k == 0) {
        head = new listNode(value, head);
      } else {
        listNode<T> *dest = head;
        for (int i = 1; i < k; i++)
          dest = dest->next;
        dest->next = new listNode(value, dest->next);
      }
      size++;
    } catch (InvalidIndexException e) {
      cout << "에러발생" << endl;
    }
  }

  void erase(int k) {
    try {
      if (k < 0 || k >= size)
        throw InvalidIndexException();
      if (k == 0) {
        listNode<T> *temp = head->next;
        delete head;
        head = temp;
      } else {
        listNode<T> *dest = head, *temp;
        for (int i = 1; i < k; i++)
          dest = dest->next;
        temp = dest->next->next;
        delete dest->next;
        dest->next = temp;
      }
      size--;
    } catch (InvalidIndexException e) {
      cout << "잘못된 인덱스입니다." << endl;
    }
  }

  int search(T value) {
    listNode<T> *temp = head;
    for (int i = 0; i < size; i++) {
      if (temp->value == value)
        return i;
      temp = temp->next;
    }
    return -1;
  }
};

int main() {
  linkedList<int> ll;
  ll.insert(0, 3);
  ll.erase(1);
}
