
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

int dy[] = {1, 0, -1, 0, 0};
int dx[] = {0, 1, 0, -1, 0};

bool in(int y, int x){
  return 0 <= y && y < 20 && 0 <= x && x < 20;
}

int main(int argc, char **argv){
  int N; cin >> N;
  vector<int> D(16, 0);
  for(int i = 0; i < 16; i++) cin >> D[i];
  
  vector<vector<int> > f(20, vector<int>(20));
  for(int i = 0; i < 20;  i++)
    for(int j = 0; j < 20; j++)
      cin >> f[i][j];
  
  for(int i = 0; i < N; i++){
    vector<vector<int> > t = f;
    for(int y = 0; y < 20; y++){
      for(int x = 0; x < 20; x++){
	int K = 0;
	for(int k = 0; k < 5; k++){
	  int ny = y + dy[k], nx = x + dx[k];
	  if(in(ny, nx)) K += f[ny][nx];
	}
	int c = f[y][x] + D[K];
	t[y][x] = min(3, max(0, c));
      }
    }
    swap(t, f);
  }
  
  char op[] = ".!X#";
  for(int y = 0; y < 20; y++){
    for(int x = 0; x < 20; x++)
      cout << op[f[y][x]];
    cout << endl;
  }
  return 0;
}
