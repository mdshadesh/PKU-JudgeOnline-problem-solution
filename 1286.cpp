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

ll a[] = {0, 3, 6, 10, 21, 39, 92, 198, 498, 1219, 3210, 8418, 22913, 62415, 173088, 481598, 1351983, 3808083, 10781954, 30615354, 87230157, 249144711, 713387076, 2046856566, 5884491500, 16946569371, 48883660146, 141217160458, 408519019449, 1183289542815};

int main(){
  int x;
  while(cin >> x, x >= 0) cout << a[x] << endl;
  return 0;
}
