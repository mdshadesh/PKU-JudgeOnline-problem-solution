
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
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    int odd = 0, even = 0;
    for(int i = 0; i < N; i++){
      int x; cin >> x;
      if(x) ((i & 1) ? odd++ : even++);
    }
    if((N & 1) || abs(odd - even) <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
