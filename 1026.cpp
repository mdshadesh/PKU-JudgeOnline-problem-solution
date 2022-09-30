
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <iostream>
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

char s[2][210];
bool vis[210];

vector<int> perm(vector<int> &a){
  int N = a.size();
  fill(vis, vis + N, false);

  vector<int> cycle(N);
  for(int i = 0; i < N; i++){
    if(vis[i]) continue;
    set<int> b;
    b.insert(i);
    vis[i] = true;
    int p = a[i];
    while(p != i){
      b.insert(p);
      vis[p] = true;
      p = a[p];
    }
    set<int>::iterator it = b.begin();
    for(; it != b.end(); it++)
      cycle[*it] = b.size();
  }
  return cycle;
}

int main(int argc, char **argv){
  int N; 
  while(scanf("%d", &N), N){
    vector<int> a(N);
    for(int i = 0; i < N; i++){
      scanf("%d", &a[i]);
      a[i]--;
    }
  
    vector<int> cycle = perm(a);

    int K;
    while(scanf("%d", &K), K){
      getchar();
      memset(s, 0, sizeof(s));
      gets(s[0]);
      int L = strlen(s[0]);
      
      for(int i = 0; i < L; i++){
	int loop = K % cycle[i];
	int p = i;
	while(loop--) p = a[p];
	s[1][p] = s[0][i];
      }
      for(int i = 0; i < N; i++){
	if(s[1][i]) putchar(s[1][i]);
	else putchar(' ');
      }
      puts("");
    }
    puts("");
  }
  return 0;
}
