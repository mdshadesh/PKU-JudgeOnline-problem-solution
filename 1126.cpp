
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
bool f(char c) { return 'p' <= c && c <= 'z'; }
string func(string s){
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'N'){
      if(i + 1 < s.size() && f(s[i + 1])){
	return s.substr(0, i) + "p" + s.substr(i + 2);
      }
    }
    if(s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I'){
      if(i + 2 < s.size() && f(s[i + 1]) && f(s[i + 2])){
	return s.substr(0, i) + "p" + s.substr(i + 3);
      }
    }
  } 
  return s;
}
int main(int argc, char **argv){
  string s;
  while(cin >> s){
    
    if(s.size() == 1){
      cout << (f(s[0]) ? "YES" : "NO") << endl;
      continue;
    }
    for(int i = 0; i < 300; i++) s = func(s);
    cout << ((s.size() == 1) ? "YES" : "NO") << endl;
    
  }
  return 0;
}
