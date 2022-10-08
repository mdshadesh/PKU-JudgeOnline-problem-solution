
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
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

string e[9] = {
  "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"
};
vector<vector<int> > affect;

inline int state(int cur, int idx){
  for(int i = 0; i < affect[idx].size(); i++){
    int b = (cur >> (2 * affect[idx][i])) & 0x3;
    b = (b + 1) % 4;
    cur &= ~(0x3 << (2 * affect[idx][i]));
    cur |= (b << (2 * affect[idx][i]));
  }
  return cur;
}

inline int prev_state(int cur, int idx){
  for(int i = 0; i < affect[idx].size(); i++){
    int b = (cur >> (2 * affect[idx][i])) & 0x3;
    b = (b + 3) % 4;
    cur &= ~(0x3 << (2 * affect[idx][i]));
    cur |= (b << (2 * affect[idx][i]));
  }
  return cur;
}

int main(int argc, char **argv){
  affect.resize(9);
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < e[i].size(); j++)
      affect[i].push_back(e[i][j] - 'A');
  
  int init = 0;
  for(int i = 0; i < 9; i++){
    int a; cin >> a;
    init |= (a << (2 * i));
  }
  
  queue<int> Q;
  Q.push(init);
  vector<int> prev(1 << 18, -1);
  
  while(!Q.empty()){
    int p = Q.front(); Q.pop();
    if(p == 0) break;
    for(int i = 0; i < 9; i++){
      int next = state(p, i);
      if(prev[next] != -1) continue;
      prev[next] = i;
      Q.push(next);
    }
  }

  vector<int> ans;
  int goal = 0;
  //while(prev[goal] > -1){
  while(1){
    if(goal== init) break;
    //cout << prev[goal] << " ";
    ans.push_back(prev[goal]);
    goal = prev_state(goal, prev[goal]);
  }
  reverse(ALL(ans));
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] + 1 << " ";
  cout << endl;
  return 0;
}
