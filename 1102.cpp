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

string digit[10][5] = {
  {" - ",
   "| |",
   "   ",
   "| |",
   " - "},
  {"   ",
   "  |",
   "   ",
   "  |",
   "   "},
  {" - ",
   "  |",
   " - ",
   "|  ",
   " - "},
  {" - ",
   "  |",
   " - ",
   "  |",
   " - "},
  {"   ",
   "| |",
   " - ",
   "  |",
   "   "},
  {" - ",
   "|  ",
   " - ",
   "  |",
   " - "},
  {" - ",
   "|  ",
   " - ",
   "| |",
   " - "},
  {" - ",
   "  |",
   "   ",
   "  |",
   "   "},
  {" - ",
   "| |",
   " - ",
   "| |",
   " - "},
  {" - ",
   "| |",
   " - ",
   "  |",
   " - "}
};

int main(int argc, char **argv){
  int n;
  string s;
  while(cin >> n >> s){
    if(n == 0 && s == "0") break;
    vector<vector<string> > out;
    for(int i = 0; i < s.size(); i++){
      vector<string> d(2 * n + 3, string(n + 2, ' '));
      string f[5] = digit[s[i] - '0'];
      for(int i = 0; i < n; i++){
	d[0][1 + i]		= f[0][1];
	d[1 + n][1 + i]		= f[2][1];      
	d[2 + 2 * n][1 + i]	= f[4][1];      
	d[1 + i][0]		= f[1][0];
	d[2 + n + i][0]		= f[3][0];
	d[1 + i][1 + n]		= f[1][2];
	d[2 + n + i][1 + n]	= f[3][2];
      }
      out.push_back(d);
    }
    int N = s.size();
    int H = out[0].size();
    for(int i = 0; i < H; i++){
      string tmp;
      for(int j = 0; j < N; j++){
	tmp += out[j][i] + " ";
      }
      cout << tmp << endl;
    }
    cout << endl;
  }
  return 0;
}
