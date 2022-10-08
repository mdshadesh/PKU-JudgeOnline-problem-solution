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

ll dp[202][202];
int main(int argc, char **argv){
  int N, K;
  for(int i = 1; i <= 200; i++) dp[i][i] = dp[i][1] = 1;
  for(int i = 2; i <= 200; i++)
    for(int j = 2; j < i; j++)
      for(int k = j; k > 0; k--)
	dp[i][j] += dp[i - j][k];
  while(cin >> N >> K, N + K) cout << dp[N][K] << endl;
  return 0;
}
