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

int gr(char c){
  if('a' <= c && c <= 'i') return 0;
  if('j' <= c && c <= 'r') return 1;
  else return 2;
}
int k[3];
int main(int argc, char **argv){
  string s;
  while(cin >> k[0] >> k[1] >> k[2], k[0] + k[1] + k[2]){
    cin >> s;
    string t = s;
    for(int i = 0; i < s.size(); i++){
      int idx = i, skip = 0;
      while(1){
	idx--;
	idx = (idx + s.size()) % s.size();
	skip += (gr(s[i]) == gr(s[idx]));
	if(skip == k[gr(s[i])]){
	  t[i] = s[idx];
	  break;
	}
      }
    }
    cout << t << endl;
  }
  return 0;
}
