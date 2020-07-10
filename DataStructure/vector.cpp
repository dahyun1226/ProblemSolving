#include <iostream>
// using namespace std;
template <typename T> class vector {
public:
  int sz;
  int capacity;
  T *vc;

  vector() {
    capacity = 8;
    sz = 0;
    vc = new T[capacity];
  }

  ~vector() { delete[] vc; }

  int size() { return sz; }

  bool empty() { return !sz; }

  void clear() {
    capacity = 8;
    sz = 0;
    delete[] vc;
    vc = new T[capacity];
  }

  void resize(int _size) {
    capacity = _size;
    T *tvc = new T[_size];
    for (int i = 0; i < sz; i++)
      tvc[i] = vc[i];
    delete[] vc;
    vc = tvc;
  }

  void push_back(T val) {
    if (sz == capacity) {
      capacity *= 2;
      resize(capacity);
    }
    vc[sz++] = val;
  }

  T &operator[](const int &i) const { return vc[i]; }

  void operator=(const vector<T> &tvc) {
    capacity = tvc.capacity;
    sz = tvc.sz;
    delete[] vc;
    vc = new T[capacity];
    for (int i = 0; i < tvc.sz; i++) {
      vc[i] = tvc[i];
    }
  }
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  std::cout << vec[1] << vec[1] << vec[1] << std::endl;
  vector<int> vec2;
  vec2 = vec;
  vec2.push_back(3);
  std::cout << vec2[0] << vec2[1] << vec2[1] << std::endl;
  return 0;
}