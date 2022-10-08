
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

using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int f[55][55];
int l[55][55];
int H, W;

void dfs(int y, int x, int label){
  l[y][x] = label;
  for(int i = 0; i < 4; i++){
    if(!(f[y][x] >> i & 1)){
      int ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny < H && 0 <= nx && nx < W && 
	 l[ny][nx] == -1)
	dfs(ny, nx, label);
    }
  }
  return;
}
int main(int argc, char **argv){
  scanf("%d", &H);
  scanf("%d", &W);
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      scanf("%d", &f[i][j]);
  
  memset(l, -1, sizeof(l));
  
  int cnt = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(l[i][j] != -1) continue;
      dfs(i, j, cnt++);
    }
  }
  vector<int> la(cnt, 0);
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      la[l[i][j]]++;
  printf("%d\n%d\n", cnt, *max_element(ALL(la)));
  return 0;
}
