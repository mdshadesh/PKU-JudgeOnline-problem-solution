
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

string i2s(int a){
  stringstream ss;
  ss << a;
  return ss.str();
}

string inv(string &s){
  int d[10] = {0};
  for(int i = 0; i < s.size(); i++) d[s[i] - '0']++;

  string ret;
  for(int c = 0; c <= 9; c++){
    if(d[c]){
      if(d[c] / 10) ret += (d[c] / 10 + '0');
      d[c] %= 10;
      ret += (d[c] + '0');
      ret += (c + '0');
    }
  }
  return ret;
}

string invent( string w )
{
    int c[10] = { 0 };
    for ( int i=0; i<(int)w.length(); i++ )
        c[w[i]-'0']++;

    string r;

    for ( int i=0; i<10; i++ )
    if ( c[i] > 0 )
    {
        if ( c[i] / 10 > 0 )
            r += char( '0' + c[i]/10 );
        r += char( '0' + c[i] % 10 );
        r += char( '0' + i );
    }

    return r;
}

int main(int argc, char **argv){
  string s;
  while(cin >> s){
    if(s == "-1") break;
    
    string f[20];
    f[0] = s;
    for(int i = 1; i <= 15; i++)
      f[i] = inv(f[i - 1]);

    int i, j;
    for(i = 0; i <= 15; i++)
      for(j = 1; i + j <= 15; j++)
	if(f[i] == f[i + j]) goto L1;
  L1:;
    
    if(i == 0 && j == 1)
      cout << f[0] << " is self-inventorying" << endl;
    else if(i <= 15 && j == 1)
      cout << f[0] << " is self-inventorying after " 
	   << i << " steps" << endl;
    else if(i <= 15)
      cout << f[0] << " enters an inventory loop of length "
	   << j << endl;
    else 
      cout << f[0] << " can not be classified after 15 iterations" << endl;
  }
  return 0;
}
