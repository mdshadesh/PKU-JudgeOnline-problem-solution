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

int v[1000010];
bool p[1000010];

int main(int argc, char **argv){
  int N, idx = 0;
  scanf("%d", &N);
  FILL(p, false);
  for(int i = 0; i < N; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a == b) p[a] = true;
    v[a]++; v[b]--;
  }
  for(int i = 1; i < 1000010; i++)
    v[i] += v[i - 1];

  bool in = false;
  for(int i = 1; i < 1000010; i++){
    if(!v[i]){
      if(in) cout << i << endl;
      if(!in && p[i]) cout << i << " " << i << endl;
      in = false;
    }else{
      if(!in) cout << i << " ";
      in = true;
    }
  }
  return 0;
}
