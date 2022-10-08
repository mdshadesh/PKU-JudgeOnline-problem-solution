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

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);



int prim(vector<vector<int>> dist){
  int N = dist.size();
  vector<bool> used(N, false);
  int ret = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
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
  int V, T;
  while(cin >> V, V){
    cin >> T;
    vector<vector<int>> d(V, vector<int>(V, INF));
    for(int i = 0; i < T; i++){
      int a, b, c;
      cin >> a >> b >> c;

      d[a - 1][b - 1] = min(d[a - 1][b - 1], c);
      d[b - 1][a - 1] = min(d[b - 1][a - 1], c);
    }

    cout << prim(d) << endl;
  }
}
