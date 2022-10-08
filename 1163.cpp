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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int dp[352][352];

int main(){
  int N;
  cin >> N;
  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= N; j++) dp[i][j] = -114514810;

  int ans = 0;
  cin >> dp[1][1];
  for(int i = 2; i <= N; i++){
    for(int j = 1; j <= i; j++){
      int s;
      cin >> s;
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + s;
      if(i == N) ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}