#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <typename T>
struct node {
  node<T> *prev;
  node<T> *next;
  T el;
};

template <class T>
class list {
  private:
    int _size;
    node<T> *fst, *lst;

  public:
    list();
    ~list();
    void push_front(T elem);
    void push_back(T elem);
    T pop_front();
    T pop_back();
    void insert(node<T>*, T);
    void erase(node<T>*);
    void print();

    int size() {
      return _size;
    }

    bool empty() {
      return _size == 0;
    }
};

template <class T> list<T>::list(){
  _size = 0;
  fst = lst = nullptr;
}

template <class T> list<T>::~list() {
  node<T> *p;
  while (fst) {
    p = fst;
    fst = fst->next;
    delete p;
  }
}

template <class T> void list<T>::push_back(T el) {
  node<T> *n = new node<T>;
  n->el = el;
  n->prev = lst;
  n->next = nullptr;

  if (this->empty()) {
    fst = n;
  } else {
    lst->next = n;
  }

  lst = n;
  _size++;
}

template <class T> void list<T>::push_front(T el) {
  node<T> *n = new node<T>;
  n->el = el;
  n->prev = nullptr;
  n->next = fst;

  if (this->empty()) {
    lst = n;
  } else {
    fst->prev = n;
  }
  fst = n;
  _size++;
}

template <class T> T list<T>::pop_front() {
  node<T> *p = fst;
  T el = p->el;
  fst = fst->next;
  fst->prev = nullptr;

  _size--;
  delete p;
  return el;
}

template <class T> T list<T>::pop_back() {
  node<T> *p = lst;
  T el = p->el;
  lst = lst->prev;
  lst->next = nullptr;

  _size--;
  delete p;
  return el;
}

template <class T> void list<T>::insert(node<T> *i, T el){
  node<T> *n = new node<T>;
  n->el = el;
  n->next = i->next;
  n->prev = i;

  i->next = n;
  _size++;
}

template <class T> void list<T>::erase(node<T> *i) {
  node<T> *prv = i->prev,
    *nxt = i->next;

  if (nxt) {
    nxt->prev = prv ? prv : nullptr;
  }
  if (prv) {
    prv->next = nxt ? nxt : nullptr;
  }

  delete i;
}

template <class T> void list<T>::print() {
  cout << "[ ";
  for(node<T> *i = fst; i != nullptr; i = i->next) {
    cout << i->el << " ";
  }
  cout << "]\n";
}


int main() {
  list<int> l1;
  l1.print();
  l1.push_back(1);
  l1.print();
  l1.push_back(2);
  l1.print();
  l1.push_back(3);
  l1.print();
  l1.push_front(0);
  l1.print();

  l1.pop_back();
  l1.print();
  l1.pop_front();
  l1.print();

  return 0;
}
