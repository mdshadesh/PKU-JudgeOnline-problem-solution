
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

using namespace std;

int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};

char f[25][25];
int main(int argc, char **argv){
  int H, W, y, x;
  while(cin >> H >> W >> y >> x, H + W + y + x){
    memset(f, '.', sizeof(f));
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
	cin >> f[i + 1][j + 1];
    W += 2, H += 2;
    int cnt = 0;
    queue<int> Q;
    Q.push(y * W + x);
    while(!Q.empty()){
      int Y = Q.front() / W, X = Q.front() % W;
      Q.pop();

      if(f[Y][X] == '*') continue;
      f[Y][X] = '*';
      for(int i = 0; i < 4; i++)
	if(f[Y + dy[i]][X + dx[i]] == '.') cnt++;
      for(int i = 0; i < 8; i++)
	if(f[Y + dy[i]][X + dx[i]] == 'X')
	  Q.push((Y + dy[i]) * W + (X + dx[i]));
    }
    cout << cnt << endl;
  }
  return 0;
}
