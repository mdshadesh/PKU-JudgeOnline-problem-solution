
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

int main(int argc, char **argv){
  int N;
  vector<pair<int, int> > pt(700);
  while(scanf("%d", &N), N){
    int y, x;
    for(int i = 0; i < N; i++){
      scanf("%d %d", &x, &y);
      pt[i] = make_pair(x, y);
    }    
    sort(pt.begin(), pt.begin() + N);
    int ans = 0;
    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N; j++){
	int cnt = 0;
	for(int k = i + 1; k < j; k++)
	  cnt += ((pt[k].second - pt[i].second) * (pt[j].first - pt[k].first) == (pt[j].second - pt[k].second) * (pt[k].first - pt[i].first));
	ans = max(ans, cnt + 2);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
