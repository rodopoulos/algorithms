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

    node<K,V>* _findinsert(K, node<K,V>*);
    void _recdestruct(node<K,V>*);
    void _print(node<K,V>*);
    node<K,V>* _erase(node<K,V>*, const K&);
    node<K,V>*inordersuc(node<K,V>*);

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


template <class K, class V> node<K,V>* map<K,V>::inordersuc(node<K,V> *p) {
  while (p->l) {
    p = p->l;
  }

  return p;
}


template <class K, class V> node<K,V>* map<K,V>::_erase(node<K,V>* r, const K& key) {
  if (key < r->key) {
    r->l = _erase(r->l, key);
  } else if(key > r->key) {
    r->r = _erase(r->r, key);
  } else {
    if (!r->l) {
      node<K,V> *a = r->r;
      delete r;
      return a;
    }

    if (!r->r) {
      node<K,V> *a = r->l;
      delete r;
      return a;
    }

    node<K,V> *a = inordersuc(r->r);
    r->key = a->key;
    r->val = a->val;
    r->r = _erase(r->r, a->key);
  }
  return r;
}


template <class K, class V> void map<K,V>::erase(const K& key) {
  if (!root) return;

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
