
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

using namespace std;

int main(int argc, char **argv){
  string s;
  while(cin >> s){
    if(s == "#") break;

    int c = 0;
    do{
      c++;
      if(c >= 2) break;
    }while(next_permutation(ALL(s)));
    cout << ((c == 1) ? "No Successor" : s) << endl;
  }
  return 0;
}