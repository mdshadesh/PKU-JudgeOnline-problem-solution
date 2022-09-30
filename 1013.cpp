
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
  int t;
  cin >> t;
  while(t--){
    bool same[12];
    FILL(same, false);
    string s[3], t[3], u[3];
    for(int i = 0; i < 3; i++){
      cin >> s[i] >> t[i] >> u[i];
      if(u[i] == "even"){
	for(int j = 0; j < 4; j++) 
	  same[s[i][j] - 'A'] = same[t[i][j] - 'A'] = true;
      }
      if(u[i] == "down") swap(s[i], t[i]);
    }

    int uneven = (u[0] != "even") + (u[1] != "even") + (u[2] != "even");

    int cnt[12];
    FILL(cnt, 0);
    for(int i = 0; i < 3; i++){
      if(u[i] == "even") continue;
      for(int j = 0; j < 12; j++) if(!same[s[i][j] - 'A']) cnt[s[i][j] - 'A']++;
    }
    int i;
    for(i = 0; i < 12; i++) if(cnt[i] == uneven) break;
    if(i < 12){
      cout << (char)(i + 'A') << " is the counterfeit coin and it is heavy." << endl;
      continue;
    }

    FILL(cnt, 0);
    for(int i = 0; i < 3; i++){
      if(u[i] == "even") continue;
      for(int j = 0; j < 12; j++) if(!same[t[i][j] - 'A']) cnt[t[i][j] - 'A']++;
    }
    for(i = 0; i < 12; i++) if(cnt[i] == uneven) break;
    if(i < 12){
      cout << (char)(i + 'A') << " is the counterfeit coin and it is light." << endl;
      continue;
    }

  }
  return 0;
}
