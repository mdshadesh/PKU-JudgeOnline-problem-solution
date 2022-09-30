
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

string mult(string s, int k){
  vector<int> ret;
  //while(s[0] == '0') s = s.substr(1);
  reverse(ALL(s));

  int i;
  int carry = 0;
  for(i = 0; i < s.size(); i++){
    //if(i == s.size() - 1 && s[i] == '0') break;
    int t = (s[i] - '0') * k + carry;
    carry = t / 10;
    ret.push_back(t % 10);
  }
  while(carry){
    ret.push_back(carry % 10);
    carry /= 10;
  }
  reverse(ALL(ret));
  string res;
  for(int i = 0; i < ret.size(); i++){
    //cout << ret[i];
    res += (char)(ret[i] + '0');
  }
  //cout << endl;

  return res;
}

bool same(string s, string t){
  sort(ALL(s));
  sort(ALL(t));
  return s == t;
}

int main(int argc, char **argv){
  string s;
  while(cin >> s){
    bool check = true;
    for(int i = 1; i <= s.size(); i++)
      if(!same(s, mult(s, i))) check = false;
    cout << s << (check ? " is cyclic" : " is not cyclic") << endl;
  }
  return 0;
}
