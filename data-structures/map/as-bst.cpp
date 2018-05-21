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
  node(int k) : l(nullptr), r(nullptr), key(k) {}
  node(int k, int v) : l(nullptr), r(nullptr), key(k), val(v) {}
};

template <class K, class V>
class map {
  private:
    int _size;
    node<K, V> *root;

    void _recdestruct(node<K,V>*);
    void _print(node<K,V>*);
    node<K,V>* _find(node<K,V>*, K);
    node<K,V>* _erase(node<K,V>*, const K&);
    node<K,V>* _findinsert(node<K,V>*, K);
    node<K,V>* _inordersuc(node<K,V>*);

  public:
    map();
    ~map();

    V& operator[](K);
    void erase(const K&);
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
  _recdestruct(root);
}


template <class K, class V>
void map<K,V>::_recdestruct(node<K,V> *p) {
  if(!p) return;

  _recdestruct(p->l);
  _recdestruct(p->r);
  delete p;
}


template <class K, class V>
node<K,V>* map<K,V>::_findinsert(node<K,V> *p, K key) {
  if (p == nullptr) {
    return new node<K,V>(key);
  } else if (key == p->key) {
      return p;
  } else if (key < p->key) {
      return _findinsert(p->l, key);
  } else { // key > p->key
      return _findinsert(p->r, key);
  }
}


template <class K, class V> V& map<K,V>::operator[](K key) {
  node<K,V> *n;
  if (root) {
    n = _findinsert(root, key);
  } else {
    n = new node<K,V>(key);
    root = n;
    _size++;
  }

  return n->val;
}


template <class K, class V> node<K,V>* map<K,V>::_inordersuc(node<K,V> *p) {
  while (p->l) {
    p = p->l;
  }

  return p;
}


template <class K, class V>
node<K,V>* map<K,V>::_find(node<K,V>* n, K key) {
  if (n == nullptr) return nullptr;

  else if (key == n->key) {
    return n;
  } else if (key < n->key){
    return _find(n->l, key);
  } else { // keu > n-->key
    return _find(n->r, key);
  }
}

template <class K, class V>
node<K,V>* map<K,V>::_erase(node<K,V>* n, const K& key) {
  if (n->l == nullptr) {
    delete n;
  }

  else if (n->r == nullptr) {
    n->key = n->l->key;
    delete n->l;
    n->l = nullptr;
  }

  else { // we have two children
    node<K,V> *a = _inordersuc(n->r);
    n->key = a->key;
    n->val = a->val;
    n->r = _erase(n->r, a->key);
    return n;
  }
}


template <class K, class V> void map<K,V>::erase(const K& key) {
  node<K,V> *n = _find(root, key);
  if (n)
    _erase(root, key);
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
  map<int,string> m1;
  m1[5] = "five";
  m1[3] = "three";
  m1[7] = "seven";
  m1[2] = "two";
  m1[4] = "four";
  m1[6] = "six";

  m1.print();
  cout << "Size: " << m1.size() << '\n';
  m1.erase(5);
  m1.print();
  m1.erase(3);
  m1.print();

  return 0;
}
