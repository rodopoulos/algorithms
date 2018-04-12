#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct node {
  node<T> *next;
  T el;
};

template <class T>
class queue {
  private:
    int _size;
    node<T> *q;

  public:
    queue();
    ~queue();
    void push(T);
    T pop();
    node<T>& front();
    node<T>& back();
    void print();

    int size() {
      return _size;
    }

    bool empty() {
      return _size == 0;
    }
};

template <class T> queue<T>::queue(){
  _size = 0;
  q = nullptr;
}

template <class T> queue<T>::~queue() {
  node<T> *p;
  while (q) {
    p = q;
    q = q->next;
    delete p;
  }
}

template <class T> void queue<T>::push(T el) {
  node<T> *p = q,
    *n = new node<T>;
  n->el = el;
  n->next = nullptr;

  if (!q) {
    q = n;
  } else {
    while (p->next)
      p = p->next;
    p->next = n;
  }

  _size++;
}

template <class T> T queue<T>::pop() {
  node<T> *p = q;
  q = q->next;
  T r = p->el;
  delete p;
  _size--;

  return r;
}

template <class T> node<T>& queue<T>::front() {
  return *q;
}

template <class T> node<T>& queue<T>::back() {
  node<T> *p = q;

  while (p->next)
    p = p->next;

  return *p;
}

template <class T> void queue<T>::print() {
  node<T> *p = q;

  cout << "< ";
  while (p) {
    cout << p->el << " ";
    p = p->next;
  }
  cout << "#\n";
}


int main() {
  queue<int> q1;
  q1.print();
  q1.push(1);
  q1.print();
  q1.push(2);
  q1.print();
  q1.push(3);
  q1.print();
  cout << "Back: " << q1.back().el << "\n";
  cout << "Front: " << q1.front().el << "\n";

  cout << q1.pop() << "\n";
  q1.print();
  cout << q1.pop() << "\n";
  q1.print();
  cout << q1.pop() << "\n";
  q1.print();

  queue<string> q2;
  q2.push("Hello");
  q2.push(",");
  q2.push("World");
  q2.push("!");
  q2.print();
  cout << q2.pop() << q2.pop() << ' ' << q2.pop() << q2.pop() << '\n';
  return 0;
}
