
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
#define EPS 1e-9
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int N, K;
double cbl[10001];

bool check(double c){
  int cnt = 0;
  for(int i = 0; i < N; i++)
    cnt += (int)((cbl[i]) / c);
  return cnt >= K;
}
int main(int argc, char **argv){
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) scanf("%lf", cbl + i);
  double ub = 1e8, lb = 0;
  for(int i = 0; i < 100; i++){
    double mid = (ub + lb) * 0.5;
    if(check(mid)) lb = mid;
    else ub = mid;
  }
  printf("%.2lf\n", floor(ub * 100) / 100);
  return 0;
}
