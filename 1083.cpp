#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int roka[200];

int main(){
  int N; cin >> N;
  for(int i = 0; i < N; i++){
    int m; cin >> m;
    fill(roka, roka + 200, 0);
    int s, t;
    for(int j = 0; j < m; j++){
      cin >> s >> t;
      s = (s - 1) / 2; t = (t - 1) / 2;
      if(s > t) swap(s, t);
      for(int k = s; k <= t; k++)
	roka[k]++;
    }
    cout << *max_element(roka, roka + 200) * 10 << endl;
  }
  return 0;
}