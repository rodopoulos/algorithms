#include <iostream>
#include <string>

using namespace std;

template <typename K, typename V>
struct node {
  node<K, V> *l;
  node<K, V> *r;
  K key;
  V val;

  node(){}
  node(int k) : key(k), l(nullptr), r(nullptr) {}
  node(int k, int v) : key(k), val(v), l(nullptr), r(nullptr) {}
};

template <class K, class V>
class map {
  private:
    int _size;
    node<K, V> *root;

    node<K,V>* _findinsert(K, node<K,V>*);
    void _recdelete(node<K,V>*);
    void _print(node<K,V>*);

  public:
    map();
    ~map();

    V& operator[](K);
    void erase(K);
    void print();

    int size() {
      return _size;
    }

    bool empty() {
      return root == nullptr;
    }
};



template <class K, class V> map<K,V>::map() {
  _size = 0;
  root = nullptr;
}


template <class K, class V> map<K,V>::~map() {
  _recdelete(root);
}


template <class K, class V>
void map<K,V>::_recdelete(node<K,V> *p) {
  if(!p) return;

  _recdelete(p->l);
  _recdelete(p->r);
  delete p;
}


template <class K, class V>
node<K,V>* map<K,V>::_findinsert(K key, node<K,V> *p) {
  if (key == p->key) {
    return p;

  } else if (key < p->key) {
    if(p->l) {
      return _findinsert(key, p->l);
    } else {
      node<K,V> *n = new node<K,V>(key);
      p->l = n;
      _size++;
      return n;
    }
  } else {
    if(p->r) {
      return _findinsert(key, p->r);
    } else {
      node<K,V> *n = new node<K,V>(key);
      p->r = n;
      _size++;
      return n;
    }
  }
}


template <class K, class V> V& map<K,V>::operator[](K key) {
  node<K,V> *n;
  if (root) {
    n = _findinsert(key, root);
  } else {
    n = new node<K,V>(key);
    root = n;
    _size++;
  }

  return n->val;
}


template <class K, class V> void map<K,V>::erase(node<K,V> *p) {

}

template <class K, class V> void map<K,V>::_print(node<K,V> *p) {
  if (!p) return;

  _print(p->l);
  cout << p->val << ' ';
  _print(p->r);
}

template <class K, class V> void map<K,V>::print() {
  _print(root);
  cout << '\n';
}


int main() {
  map<int,int> m1;
  m1[1] = 1;
  m1.print();
  m1[2] = 2;
  m1.print();
  m1[4] = 4;
  m1.print();
  m1[3] = 3;
  m1.print();
  m1[5] = 5;
  m1.print();
  cout << "Size: " << m1.size() << '\n';
  cout << "Element 2 is " << m1[2] << '\n';
  cout << "Size: " << m1.size() << '\n';

  return 0;
}
