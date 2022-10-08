#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int n, m;
int c[5], k[5], p[5], offerp[100];
vector<vector<pair<int, int> > > offer;
const int MX = 6 * 6 * 6 * 6 * 6;
int cost[MX];

void dfs(int cur){
  int rest = 0; bool ok = true;
  for(int i = 0; i < n; i++){
    rest += k[i] * p[i];
    if(k[i]) ok = false;
  }
  cost[0] = min(cost[0], cur + rest);
  if(ok) return;

  for(int i = 0; i < m; i++){
    int hash;
    
    for(int j = 0; j < (int)offer[i].size(); j++)
      if(k[offer[i][j].first] < offer[i][j].second)
	goto FAIL;
    for(int j = 0; j < (int)offer[i].size(); j++)
      k[offer[i][j].first] -= offer[i][j].second;

    hash = 0;
    for(int j = 0; j < n; j++)
      hash *= 6, hash += k[j];
    if(cost[hash] > cur + offerp[i]){
      cost[hash] = cur + offerp[i];
      dfs(cur + offerp[i]);
    }
    for(int j = 0; j < (int)offer[i].size(); j++)
      k[offer[i][j].first] += offer[i][j].second;
  FAIL:;
  }
}

int main(){
  offer.clear();
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> c[i] >> k[i] >> p[i];
  cin >> m;
  offer.resize(m);
  for(int i = 0; i < m; i++){
    int t, x, y;
    cin >> t;
    for(int j = 0; j < t; j++){
      cin >> x >> y;
      x = find(c, c + n, x) - c;
      offer[i].push_back(make_pair(x, y));
    }
    cin >> offerp[i];
  }
  fill(cost, cost + MX, INF);
  dfs(0);
  cout << cost[0] << endl;
  return 0;
}