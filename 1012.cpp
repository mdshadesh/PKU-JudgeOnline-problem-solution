#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

bool used[20];

int check(int k, int g, int n, int now){
  while(1){
    now = (now + n - 1) % (k + g);
    if(k == 0) return true;
    if(now >= g) k--;
    else return false;
  }
}

int solve(int k){
  for(register int i = 1; i <= 10000000; i++)
    if(check(k, k, i, 0)) return i;

  return -1;
}

int ans[13];
int main(){
  int k;
  for(int i = 1; i <= 13; i++) ans[i - 1] = solve(i);
  while(cin >> k, k){
    cout << ans[k - 1] << endl;
  }
  return 0;
}
