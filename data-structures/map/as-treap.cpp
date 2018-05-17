#include <iostream>
#include <string>

using namespace std;

template <typename K, typename V>
struct node {
  node<K, V> *l, // left node
    *r, // right node
    *p; // parent node

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
    V& lower_bound(const K&);
    V& upper_bound(const K&);
    void erase(const K&);
    void print();

    int size() { return _size; }
    bool empty() { return root == nullptr; }
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

}


template <class K, class V> V& map<K,V>::operator[](K key) {
  
}


template <class K, class V> node<K,V>* map<K,V>::inordersuc(node<K,V> *p) {

}


template <class K, class V> node<K,V>* map<K,V>::_erase(node<K,V>* r, const K& key) {

}


template <class K, class V> void map<K,V>::erase(const K& key) {
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

  return 0;
}
