#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);


int main(int argc, char **argv){
  int G, L;
  ll dp[31][31];
  FILL(dp, 0);
  for(int i = 1; i <= 30; i++)
    for(int j = 0; j <= 30; j++)
      dp[i][j] = (j == 0 ? 0 : dp[i - 1][j - 1]) + 1 + dp[i - 1][j];

  int idx = 1;
  while(scanf("%d %d", &G, &L), G + L)
    printf("Case %d: %d\n", idx++, dp[G][L]);
}
