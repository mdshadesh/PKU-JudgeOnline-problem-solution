
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

int R, C;
int f[20][20];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x, vector<bool> &vis){
  int ans = 0;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(0 <= nx && nx < C && 0 <= ny && ny < R && !vis[f[ny][nx]]){
      vis[f[ny][nx]] = true;
      ans = max(ans, 1 + dfs(ny, nx, vis));
      vis[f[ny][nx]] = false;
    }
  }
  return ans;
}

int main(int argc, char **argv){
  cin >> R >> C;
  for(int i = 0; i < R * C; i++){
    char a;
    cin >> a;
    f[i / C][i % C] = (int)(a - 'A');
  }
  vector<bool> t = vector<bool>(26, false);
  t[f[0][0]] = true;
  cout << 1 + dfs(0, 0, t) << endl;
  return 0;
}
