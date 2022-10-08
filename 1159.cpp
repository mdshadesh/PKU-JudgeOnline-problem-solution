
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

short dp[5001][5001];

int main(){
  int N;
  string s;
  cin >> N;
  cin >> s;

  for(int i = N - 1; i >= 0; i--){
    for(int j = i; j < N; j++){
      if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
      else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
    }
  }
  cout << dp[0][N - 1] << endl;
  return 0;
}