
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
  cin >> N;
  while(N--){
    int T;
    cin >> T;
    string pa;
    int prev = 0;
    for(int i = 0; i < T; i++){
      int cur;
      cin >> cur;
      pa += string(cur - prev, '(') + ")";
      prev = cur;
    }
    for(int i = 0; i < pa.size(); i++){
      if(pa[i] == ')'){
	int idx = i;
	while(pa[--idx] != '(');
	pa[i] = pa[idx] = ' ';
	cout << (i - idx + 1) / 2 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}