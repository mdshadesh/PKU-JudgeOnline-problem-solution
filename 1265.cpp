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
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  for(int t = 1; t <= N; t++){
    int x[101], y[101];
    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++) cin >> x[i] >> y[i];

    int E = 0;
    double A = 0.0;
    for(int i = 0; i < M; i++) E += gcd(abs(x[i]), abs(y[i]));
    for(int i = 1; i < M; i++) x[i] += x[i - 1], y[i] += y[i - 1];
    for(int i = 0; i < M; i++)
      A += 0.5 * (x[i] * y[(i + 1) % M] - y[i] * x[(i + 1) % M]);
    A = fabs(A);
    printf("Scenario #%d:\n", t);
    printf("%d %d %.1f\n\n", (int)(A + 1 - 0.5 * E), E, A);
  }
  return 0;
}
