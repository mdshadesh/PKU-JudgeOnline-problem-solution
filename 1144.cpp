
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

int N;
bool E[101][101], tmp[101][101];

inline bool reach(int idx){
  int start = (idx + 1) % N;
  queue<int> Q;
  Q.push(start);
  bool vis[100];
  FILL(vis, false);
  vis[start] = true;
  while(!Q.empty()){
    int from = Q.front(); Q.pop();
    for(int i = 0; i < N; i++){
      if(tmp[from][i] && !vis[i]){
	vis[i] = true;
	Q.push(i);
      }
    }
  }
  return count(vis, vis + N, false) == 1;
}

int main(int argc, char **argv){
  while(cin >> N, N){
    FILL(E, false);
    string s;
    while(1){
      getline(cin, s);
      if(s[0] == '0') break;
      
      stringstream ss(s);
      int f, t;
      ss >> f;
      while(ss >> t) E[f - 1][t - 1] = E[t - 1][f - 1] = true;
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
      memcpy(tmp, E, 101 * 101 * sizeof(bool));
      for(int j = 0; j < N; j++) tmp[i][j] = tmp[j][i] = false;
      ans += !reach(i);
    }
    cout << ans << endl;
  }
  return 0;
}
