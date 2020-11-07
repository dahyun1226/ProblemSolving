#include <iostream>
using namespace std;
class UnderflowException {};
template <typename T> class listNode {
public:
  T value;
  listNode<T> *next;
  listNode<T>() : next(nullptr) {}
  listNode<T>(T value1, listNode<T> *next1) : value(value1), next(next1) {}
};
template <typename T> class queue {
public:
  int size;
  listNode<T> *head, *tail;
  queue<T>() : size(0), head(nullptr), tail(nullptr) {}
  ~queue<T>() {
    listNode<T> *t1 = head, *t2;
    while (t1 != nullptr) {
      t2 = t1->next;
      delete t1;
      t1 = t2;
    }
  }
  void push(T value) {
    if (size == 0) {
      head = tail = new listNode<T>(value, nullptr);
    } else {
      tail->next = new listNode<T>(value, nullptr);
      tail = tail->next;
    }
    size++;
  }
  T front() {
    try {
      if (size == 0) {
        throw UnderflowException();
      }
      return head->value;
    } catch (UnderflowException e) {
      cout << "언더플로 발생" << endl;
    }
  }
  void pop() {
    try {
      if (size == 0) {
        throw UnderflowException();
      }
      listNode<T> *t1;
      t1 = head;
      head = head->next;
      delete t1;
      if (head == nullptr)
        tail = nullptr;
      size--;
    } catch (UnderflowException e) {
      cout << "언더플로 발생!" << endl;
    }
  }
};
int main() {
    queue<int>q;
    q.push(3);
    cout<<q.front()<<endl;
    q.pop();
    q.push(5);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}