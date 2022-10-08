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

int S, X, Y, A, L, B, R, T;
ll bit[2010][2010];
void add(int a, int b, int w){
  for(int x = a; x <= S; x += x & -x)
    for(int y = b; y <= S; y += y & -y)
      bit[x][y] += w;
}
ll sum(int a, int b){
  int ret = 0;
  for(int x = a; x > 0;  x -= x & -x)
    for(int y = b; y > 0; y -= y & -y)
      ret += bit[x][y];
  return ret;
}
ll qsum(int x0, int y0, int x1, int y1){
  return sum(x1, y1) - sum(x0 - 1, y1) - sum(x1, y0 - 1) + sum(x0 - 1, y0 - 1);
}

int main(){
  int c;
  while(scanf("%d", &c)){
    if(c == 0){
      scanf("%d", &S);
    }else if(c == 1){
      scanf("%d %d %d", &X, &Y, &A);
      add(X + 1, Y + 1, A);
    }else if(c == 2){
      scanf("%d %d %d %d", &L, &B, &R, &T);
      cout << qsum(L + 1, B + 1, R + 1, T + 1) << endl;
    }else
      break;
  }
  return 0;
}
