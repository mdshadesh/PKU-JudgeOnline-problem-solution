#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

#define INF 1 << 29

int prim(vector<vector<int> > dist){
  int N = dist.size();
  vector<bool> used(N, false);
  int ret = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
  Q.push(make_pair(0, 0));
  while(!Q.empty()){
    int cost = Q.top().first;
    int to = Q.top().second;
    Q.pop();
    if(used[to]) continue;
    used[to] = true;
    ret += cost;
    for(int i = 0; i < N; i++) Q.push(make_pair(dist[to][i], i));
  }
  return ret;
}

int main(int argc, char **argv){
  int N;
  while(cin >> N, N){
    vector<vector<int> > g(N, vector<int>(N, INF));
    for(int k = 0; k < N - 1; k++){
      char a;
      int b;
      cin >> a >> b;
      for(int i = 0; i < b; i++){
	char c;
	int d;
	cin >> c >> d;
	g[a - 'A'][c - 'A'] = g[c - 'A'][a - 'A'] = d;
      }
    }
    cout << prim(g) << endl;
  }
}
