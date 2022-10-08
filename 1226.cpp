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

    string minstr("z", 101);
    vector<string> s(N);
    for(int i = 0; i < N; i++){
      cin >> s[i];
      if(minstr.size() > s[i].size()) minstr = s[i];
      
      string t(s[i]);
      reverse(ALL(t));
      s[i] += "#" + t;
    }
    
    int len = 0;
    for(int w = minstr.size(); w >= 1; w--){
      for(int i = 0; i + w <= minstr.size(); i++){
	string cand = minstr.substr(i, w);
	
	bool check = true;
	for(int k = 0; k < N; k++){
	  if(s[k].find(cand) == string::npos){
	    check = false;
	    break;
	  }
	}
	if(check){
	  len = w;
	  goto L1;
	}
      }
    }
  L1:;
    cout << len << endl;
  }
  return 0;
}
