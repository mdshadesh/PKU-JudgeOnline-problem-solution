#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int par[15000], rank[15000];

void uf_init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int uf_find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = uf_find(par[x]);
  }
}

void uf_unite(int x, int y){
  x = uf_find(x);
  y = uf_find(y);
  if(x == y) return;

  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool uf_same(int x, int y){
  return uf_find(x) == uf_find(y);
}


struct edge{int u, v, cost;};

bool comp(const edge &e1, const edge &e2){
  return e1.cost < e2.cost;
}

edge es[15000];
int V, E;

int kruscal(){
  sort(es, es + E, comp);
  uf_init(V);
  int res = 0;
  for(int i = 0; i < E; i++){
    edge e = es[i];
    if(!uf_same(e.u, e.v)){
      uf_unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main(){
  int N;
  while(scanf("%d\n", &N) != EOF){
    V = N;
    E = V * V;
    int cnt = 0;
    for(int i = 0; i < V; i++){
      for(int j = 0; j < V; j++){
	int a; scanf("%d", &a);
	es[cnt].u = j; 
	es[cnt].v = i; 
	es[cnt].cost = a; 
	cnt++;
      }
    }
    printf("%d\n", kruscal());
  }
  return 0;
}