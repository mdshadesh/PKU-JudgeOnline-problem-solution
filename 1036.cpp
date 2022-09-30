#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

struct gang{
  int t, p, s;
  bool operator<(const gang &e)const{
    return t < e.t;
  }
};

gang g[100];
int dp[101];

int main(){
  int N, K, T; cin >> N >> K >> T;
  for(int i = 1; i <= N; i++) cin >> g[i].t;
  for(int i = 1; i <= N; i++) cin >> g[i].p;
  for(int i = 1; i <= N; i++) cin >> g[i].s;

  sort(g + 1, g + N + 1);
  
  memset(dp, 0, sizeof(dp));
  g[0].t = 0; g[0].p = 0; g[0].s = 0;

  for(int i = 1; i <= N; i++){
    for(int j = i - 1; j >= 0; j--){
      if(dp[j] >= g[j].p)
	if(abs(g[i].s - g[j].s) <= g[i].t - g[j].t)
	  dp[i] = max(dp[i], dp[j] + g[i].p);
    }
  }
  cout << *max_element(dp, dp + N + 1) << endl;
  return 0;
}