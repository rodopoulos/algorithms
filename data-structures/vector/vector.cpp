#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class T>
class vector {
  private:
    static const int INITIALSIZE = 5;
    int _size, _cap;
    T *v;

    void realocate();

  public:
    vector();
    vector(int sz);
    ~vector();
    void push_back(T elem);
    void erase(int pos);
    void print();
    T at(int pos);
    T& operator[](int);
    const T& operator[](int) const;

    int size() {
      return _size;
    }

    bool empty() {
      return _size == 0;
    }
};

template <class T> void vector<T>::realocate() {
  T *n = new T[_cap * 2];
  memcpy(n, v, _size * sizeof(T));
  _cap = _cap << 1;
  delete[] v;
  v = n;
}

template <class T> vector<T>::vector(){
  _size = 0;
  _cap = 5;
  v = new T[_cap];
}

template <class T> vector<T>::vector(int sz){
  _size = 0;
  _cap = sz;
  v = new T[_cap];
}

template <class T> vector<T>::~vector() {
  delete[] v;
}

template <class T> void vector<T>::push_back(T el) {
  if (_size + 1 > _cap) {
    realocate();
  }
  v[_size] = el;
  _size++;
}

template <class T> void vector<T>::erase(int pos) {
  for (int i = pos; i < _size-1; i++) {
    v[i] = v[i+1];
  }
  _size--;
}

template <class T> T vector<T>::at(int pos) {
  return v[pos];
}

template <class T> T& vector<T>::operator[](int i) {
  return v[i];
}

template <class T> const T& vector<T>::operator[](int i) const {
  return v[i];
}

template <class T> void vector<T>::print() {
  cout << "[ ";
  for(int i = 0; i < _size; i++) {
    cout << v[i] << " ";
  }
  cout << "]\n";
}


int main() {
  vector<int> v1;
  v1.print();
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  v1.print();
  v1.push_back(5);
  v1.print();
  v1.push_back(6);
  v1.print();

  v1[3] = 10;
  v1.print();

  v1.erase(1);
  v1.print();

  vector<string> vs;
  vs.push_back("Hello");
  vs.push_back(", ");
  vs.push_back("world");
  vs.push_back("!");
  for (int i = 0; i < vs.size(); i++){
    cout << vs.at(i);
  }
  cout << "\n";

  return 0;
}
