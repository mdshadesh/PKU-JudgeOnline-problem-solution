#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_V = 300;
const int INF = 10000000;

struct edge {int to, cap, rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];

int min(int a, int b){
  return (a > b) ? b : a;
}

void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size() - 1});
}


int dfs(int v, int t, int f){
  if(v == t) return f;
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow = 0;
  for(;;){
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if(f == 0) return flow;
    flow += f;
  }
}


int main(int argc, char **argv){
  int N, M;
  while(cin >> N >> M){
    for(int i = 0; i < MAX_V; i++) G[i].clear();
    for(int i = 0; i < N; i++){
      int v1, v2, v3;
      cin >> v1 >> v2 >> v3;
      add_edge(v1, v2, v3);
    }
    cout << max_flow(1, M) << endl;
  }
}
