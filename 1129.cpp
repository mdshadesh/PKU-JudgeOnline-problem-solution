
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

int color[30];
bool adj[30][30];
int n;

int ret(int idx){
  bool used[4] = {false};
  for(int i = 0; i < n; i++)
    if(adj[idx][i] && color[i] != -1)
      used[color[i]] = true;
  for(int i = 0; i < 4; i++)
    if(!used[i]) return i;
}
void dfs(int i){
  for(int j = 0; j < n; j++){
    if(!adj[i][j] || color[j] != -1) continue;
    //cout << i << " " << j << endl;
    color[j] = ret(j);
    dfs(j);
  }
  return;
}

int main(int argc, char **argv){
  while(scanf("%d", &n), n){
    FILL(color, -1);
    FILL(adj, false);
    for(int k = 0; k <n; k++){
      char s[30]; scanf("%s", s);    
      for(int i = 2; i < strlen(s); i++)
	adj[s[0] - 'A'][s[i] - 'A'] = true;
    }

    for(int i = 0; i < n; i++){
      if(color[i] != -1) continue;
      color[i] = 0;
      dfs(i);
    }
    // for(int i = 0; i < n; i++) cout << color[i] << " ";
    // cout << endl;
    set<int> r(color, color + n);
    if(r.size() == 1)
      printf("%d channel needed.\n", r.size());
    else
      printf("%d channels needed.\n", r.size());
  }
  return 0;
}
