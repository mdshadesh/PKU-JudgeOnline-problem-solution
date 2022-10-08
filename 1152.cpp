
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

int num[256];
int main(int argc, char **argv){
  for(int i = 0; i < 10; i++) num[i + '0'] = i;
  for(int i = 0; i < 26; i++) num[i + 'A'] = i + 10, num[i + 'a'] = i + 36;

  string in;
  while(cin >> in){
    if(in == "0"){
      cout << "2" << endl;
      continue;
    }
    ll base = 0;
    for(int i = 0; i < in.size(); i++) base = max(base, (ll)num[in[i]] + 1);
    for(; base <= 62; base++){
      ll ret = 0;
      for(int i = 0; i < in.size(); i++){
	ret = ret * base + num[in[i]];
	ret %= (base - 1);
      }
      if(ret == 0) break;
    }
    if(base == 63) cout << "such number is impossible!" << endl;
    else	   cout << base << endl;
  }
  return 0;
}
