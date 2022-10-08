#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

class UnionFind{
public:
  UnionFind();
  UnionFind(int num){
    for(int i = 0; i < num; i++) parent[i] = i, rank[i] = 0;
  }

  bool same (int x, int y) { return find(x) == find(y); }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rank[y] > rank[x]){
      parent[x] = y;
    }else{
      parent[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

private:
  int rank[200005], parent[200005];

  int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
  }
};


int main(int argc, char **argv){
  int N, K;
  scanf("%d %d", &N, &K);
  UnionFind uf(3 * N + 1);
  int ans = 0;
  for(int i = 0; i < K; i++){
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--, y--;
    if(x >= N || y >= N || x < 0 || y < 0){
      ans++;
      continue;
    }
    if(t == 1){
      if(uf.same(x, y + N) || uf.same(x, y + 2 * N)){
	ans++;
	continue;
      }
      uf.unite(x, y);
      uf.unite(x + N, y + N);
      uf.unite(x + 2 * N, y + 2 * N);
    }else{
      if(uf.same(x, y) || uf.same(x, y + 2 * N)){
	ans++;
	continue;
      }      
      uf.unite(x, y + N);
      uf.unite(x + N, y + 2 * N);
      uf.unite(x + 2 * N, y);
    }
  }
  printf("%d\n", ans);
  return 0;
}
