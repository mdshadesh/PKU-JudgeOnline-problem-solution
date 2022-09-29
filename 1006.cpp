
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
  int p, e, i, d, idx = 0;
  while(scanf("%d %d %d %d", &p, &e, &i, &d)){
    if(p == -1) break;
    for(int a = 1; ; a++){
      if((a + d - p) % 23 == 0 && 
	 (a + d - e) % 28 == 0 && 
	 (a + d - i) % 33 == 0){
	printf("Case %d: the next triple peak occurs in %d days.\n",
	       ++idx, a);
	break;
      }
    }
  }
  return 0;
}
