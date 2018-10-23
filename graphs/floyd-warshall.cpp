#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define oo 1000*1000*1000
#define _oo -1*1000*1000*1000

int D[N][N][N];

int floydwarshall(int i, int j, int k) {
  if (k == 0 || D[i][j][k] != _oo) {
    return D[i][j][k];
  }

  int
   a = floydwarshall(i, j, k-1),
   b = floydwarshall(i, k, k-1) + floydwarshall(k, j, k-1);
  D[i][j][k] = min(a, b);
  return D[i][j][k];
}

int main () {

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        D[i][j][k] = _oo;

  // Inicializa D[i][j][0] com o grafo desejado
  floydwarshall(N, N, N);

  return 0;
}
