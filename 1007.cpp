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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int inversion(string a){
  int N = a.length();
  int cnt = 0;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      if(a[i] > a[j]) cnt++;
    }
  }
  return cnt;
}

int main(){
  vector<pair<int, string> > ps;
  int n, m;
  cin >> n >> m;
  string tmp;
  for(int i = 0; i < m; i++){
    cin >> tmp;
    ps.push_back(make_pair(inversion(tmp), tmp));
  }
  sort(ps.begin(), ps.end());
  for(int i = 0; i < m; i++){
    cout << ps[i].second << endl;
  }

  return 0;
}