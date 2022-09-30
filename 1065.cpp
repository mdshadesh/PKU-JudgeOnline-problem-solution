#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int INF = 10000000;

bool used[5000];

int main(){
  int T; cin >> T;
  while(T--){

    vector<pair<int, int> > lw;
    int n, l, w; cin >> n;
    for(int i = 0; i < n; i++){
      cin >> l >> w;
      lw.push_back(make_pair(l, w));
    }

    sort(lw.begin(), lw.end());
    memset(used, 0, sizeof(used));

    int ans = 0;
    for(int i = 0; i < n; i++){
      if(used[i]) continue;
      used[i] = true;
      ans++;
      int ti = i;
      for(int j = i + 1; j < n; j++){
	if(used[j])continue;
	if(lw[ti].second <= lw[j].second){
	  used[j] = true;
	  ti = j;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}