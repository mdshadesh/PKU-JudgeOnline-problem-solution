
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

inline int s(int x){
  int ret = 0;
  while(x){
    ret += (x % 10);
    x /= 10;
  }
  return ret;
}
bool smith(int x){
  int factsum = 0, sum = s(x);
  int y = x;
  for(int i = 2; i * i <= y; i++){
    while(y % i == 0){
      factsum += s(i);
      y /= i;
    }
  }
  if(y != 1) factsum += s(y);
  if(x == y) factsum = 0;
  return factsum == sum;
}
int main(int argc, char **argv){
  int x;
  while(cin >> x, x){
    while(!smith(++x));
    cout << x << endl;
  }
  return 0;
}
