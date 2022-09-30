#include <algorithm>
#include <cstdio>
using namespace std;

int map[100][100];
int dp[100][100];

int dx[4] = {1, 0, -1, 0};


int R, C;

int dfs(int y, int x){
  int &res=dp[y][x];
  if(!res){
    res = 1;
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dx[i^1];
      if(0 <= nx && nx < C
	 && 0 <= ny && ny < R && map[ny][nx] < map[y][x])
	res = max(1 + dfs(ny, nx), res);
    }
  }
  return res;
}

int main(){
  scanf("%d %d", &R, &C);
  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
      scanf("%d", &map[i][j]);

  int res = 0;
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      res = max(res, dfs(i, j));
    }
  }

  printf("%d\n", res);
  return 0;
}