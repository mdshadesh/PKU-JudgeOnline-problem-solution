#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);

int dp[101][101];

int main(int argc, char **argv){
  int n;
  while(cin >> n, n){
    FILL(dp, INF);
    for(int i = 0; i < n; i++){
      int k; cin >> k;
      for(int j = 0; j < k; j++){
	int a, b; cin >> a >> b;
	dp[i][a - 1] = b;
      }
      dp[i][i] = 0;
    }
    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	  dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
    
    int idx = 0;
    for(int i = 0; i < n; i++)
      if(*max_element(dp[idx], dp[idx] + n) > *max_element(dp[i], dp[i] + n))
	idx = i;
    
    int ans = *max_element(dp[idx], dp[idx] + n);
    if(ans >= INF) cout << "disjoint" << endl;
    else cout << idx + 1 << " " << ans << endl;
  }
  return 0;
}