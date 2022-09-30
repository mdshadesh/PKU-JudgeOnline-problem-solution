
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
#include <math.h>
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

struct seq {
  int n;
  int num[70];
  double logsum;
};

seq dp[1010];
int main(int argc, char **argv){
  int N;
  cin >> N;
  
  for(int i = 0; i < 1000; i++){
    dp[i].n = 0;
    dp[i].logsum = 0;
  }

  for(int i = 0; i <= N; i++){
    int lastnum = i == 0 ? 1 : dp[i].num[dp[i].n - 1];
    for(int j = lastnum + 1; j <= N; j++){
      if(i + j == N || N - i - j > j){
	double a = dp[i + j].logsum;
	double b = dp[i].logsum + log((double)j);
	if(a < b){
	  memcpy(dp[i + j].num, dp[i].num, dp[i].n * sizeof(int));
	  dp[i + j].num[dp[i].n] = j;
	  dp[i + j].n = dp[i].n + 1;
	  dp[i + j].logsum = b;
	}
      }
    }
  }

  int sum = 0;
  for(int i = 0; i < dp[N].n; i++)
    cout << dp[N].num[i] << " ";
  cout << endl;
  //dump(sum);
  return 0;
}
