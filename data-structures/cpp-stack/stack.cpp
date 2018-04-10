#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct node {
  node<T> *next;
  T el;
};

template <class T>
class stack {
  private:
    int _size;
    node<T> *s;

  public:
    stack();
    ~stack();
    void push(T elem);
    T top();
    T pop();
    void print();

    int size() {
      return _size;
    }

    bool empty() {
      return _size == 0;
    }
};

template <class T> stack<T>::stack(){
  _size = 0;
  s = nullptr;
}

template <class T> stack<T>::~stack() {
  node<T> *p;
  while (s) {
    p = s;
    s = s->next;
    delete p;
  }
}

template <class T> void stack<T>::push(T el) {
  node<T> *p;
  p = new node<T>;
  p->el = el;
  p->next = s;
  s = p;
  _size++;
}

template <class T> T stack<T>::pop() {
  node<T> *p;
  p = s;
  T r = s->el;
  s = p->next;
  delete p;
  _size--;

  return r;
}

template <class T> T stack<T>::top() {
  return s->el;
}

template <class T> void stack<T>::print() {
  node<T> *p;
  p = s;
  while (p) {
    cout << p->el << " ";
    p = p->next;
  }
  cout << "#\n";
}


int main() {
  stack<int> s1;
  s1.print();
  s1.push(1);
  s1.print();
  s1.push(2);
  s1.print();
  s1.push(3);
  s1.print();
  cout << "Size:" << s1.size() << "\n";
  cout << "Top:" << s1.top() << "\n";

  s1.print();
  cout << s1.pop() << "\n";
  s1.print();
  cout << s1.pop() << "\n";
  s1.print();
  cout << s1.pop() << "\n";
  cout << "Size:" << s1.size() << "\n";

  stack<string> s2;
  s2.push("!");
  s2.push("World");
  s2.push(",");
  s2.push("Hello");
  s2.print();
  cout << s2.pop() << '\n';
  cout << s2.pop() << '\n';
  cout << s2.pop() << '\n';
  return 0;
}
