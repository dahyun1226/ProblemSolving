#include <iostream>
using namespace std;
class UnderflowException {};

template <typename T> class Node {
public:
  T value;
  Node<T> * next;
  Node<T>() : next(nullptr) {}
  Node<T>(T value1, Node<T> *next1) : value(value1), next(next1) {}
};

template <typename T> class Stack {
public:
  int size;
  Node<T> *tail;
  Stack<T>() : size(0), tail(nullptr) {}
  ~Stack<T>() {
    Node<T> *t1 = tail, *t2;
    while (t1 != nullptr) {
      t2 = t1->next;
      delete t1;
      t1 = t2;
    }
  }
  void push(T value) {
    tail = new Node<T>(value, tail);
    size++;
  }
  T top() {
    try {
      if (size == 0)
        throw UnderflowException();
      return tail->value;
    } catch (UnderflowException e) {
      cout << "스택 비었다!" << endl;
    }
  }
  void pop() {
    try {
      if (size == 0)
        throw UnderflowException();
      Node<T> *temp = tail;
      delete tail;
      tail = temp->next;
      size--;

    } catch (UnderflowException e) {
      cout << "스택 비었다!" << endl;
    }
  }
};

int main(){
    Stack<int> S;
    S.push(0); cout << S.top() << endl;
    S.push(1); cout << S.top() << endl;
    S.push(2); cout << S.top() << endl;
    S.push(3); cout << S.top() << endl;
    S.pop(); cout << S.top() << endl;
    S.push(4); cout << S.top() << endl;
    S.pop(); cout << S.top() << endl;
    S.pop(); cout << S.top() << endl;
    S.push(5); cout << S.top() << endl;
    S.pop(); cout << S.top() << endl;
}

