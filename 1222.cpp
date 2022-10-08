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

void flip(vector<vector<bool> > &f, int y, int x){
  f[y][x] = !f[y][x];
  if(0 <= y - 1)   f[y - 1][x] = !f[y - 1][x];
  if(0 <= x - 1)   f[y][x - 1] = !f[y][x - 1];
  if(y + 1 < 5)   f[y + 1][x] = !f[y + 1][x];
  if(x + 1 < 6)   f[y][x + 1] = !f[y][x + 1];  
}

int main(){
  int M; cin >> M;
  for(int m = 0; m < M; m++){
    vector<vector<bool> > init(5, vector<bool>(6, false));
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 6; j++){
	char c; cin >> c;
	init[i][j] = c == '1';
      }
    for(int S = 0; S < 1 << 6; S++){
      vector<vector<bool> > t = init;
      vector<vector<bool> > sw(5, vector<bool>(6, false));
      for(int j = 0; j < 6; j++){
	if(S >> j & 1){
	  flip(t, 0, j);
	  sw[0][j] = true;
	}
      }
      
      for(int i = 1; i < 5; i++){
	for(int j = 0; j < 6; j++){
	  if(t[i - 1][j]){
	    flip(t, i, j);
	    sw[i][j] = true;
	  }
	}
      }

      int cnt = 0;
      for(int i = 0; i < 5; i++)
	for(int j = 0; j < 6; j++)      
	  cnt += t[i][j];
      
      if(cnt == 0){
	cout << "PUZZLE #" << m + 1 << endl;
	for(int i = 0; i < 5; i++){
	  for(int j = 0; j < 6; j++)
	    cout << sw[i][j] << " ";
	  cout << endl;
	}
      }
    }
  }
}
