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

  vector<ll> c(5);
ll calc(string &s){
  for(int i = 0; i < 5; i++) c[i] = s[i] - 'A' + 1;
  return c[0] 
    - c[1] * c[1] 
    + c[2] * c[2] * c[2]
    - c[3] * c[3] * c[3] * c[3]
    + c[4] * c[4] * c[4] * c[4] * c[4];
}

int main(int argc, char **argv){
  ll d;
  string s;
  while(cin >> d >> s){
    if(d == 0 && s == "END") break;
    sort(ALL(s));
    int L = s.length();
    string ans("AAAAA");
    string str("AAAAA");
    for(int S = 0; S < 1 << L; S++){
      if(__builtin_popcount(S) != 5) continue;
      
      int idx = 0;
      for(int i = 0; i < L; i++) if(S >> i & 1) str[idx++] = s[i];
      
      do{
	if(calc(str) == d) ans = max(ans, str);
      }while(next_permutation(ALL(str)));
    }

    if(ans == "AAAAA")	cout << "no solution" << endl;
    else		cout << ans << endl;
  }
  return 0;
}
