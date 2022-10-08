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
#include <complex>

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

int add(int a, int b){
  if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}

struct P{
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
  P operator + (P p){
    return P(add(x, p.x), add(y, p.y));
  }
  P operator - (P p){
    return P(add(x, -p.x), add(y, -p.y));
  }
  P operator * (int d){
    return P(x * d, y * d);
  }
  int dot(P p){
    return add(x * p.x, y * p.y);
  }
  int det(P p){
    return add(x * p.y, -y * p.x);
  }
};

bool cmp_x(P a, P b){
  if(a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

vector<P> convex_hull(vector<P> &p){
  int N = p.size();
  sort(p.begin(), p.end(), cmp_x);
  int k = 0;
  vector<P> ret(N * 2);
  for(int i = 0; i < N; i++){
    while(k > 1 && (ret[k - 1] - ret[k - 2]).det(p[i] - ret[k - 1]) <= 0) k--;
    ret[k++] = p[i];
  }
  for(int i = N - 2, t = k; i >= 0; i--){
    while(k > t && (ret[k - 1] - ret[k - 2]).det(p[i] - ret[k - 1]) <= 0) k--;
    ret[k++] = p[i];
  }
  ret.resize(k - 1);
  return ret;
}


int main(int argc, char **argv){
  int T;
  cin >> T;
  while(T--){
    int N;
    vector<P> p;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
      P tmp;
      scanf("%d %d", &tmp.x, &tmp.y);
      p.push_back(tmp);
    }

    vector<P> ch = convex_hull(p);
    int M = ch.size();

    vector<bool> online(M, false);
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	P p1 = ch[(j + 1) % M] - p[i];
	P p2 = ch[j] - p[i];
	if(p1.x == 0 && p1.y == 0) continue;
	if(p2.x == 0 && p2.y == 0) continue;
	if( (ch[(j + 1) % M] - ch[j]).det(p[i] - ch[j]) == 0)
	  online[j] = true;
      }
    }

    double area = 0.0;
    bool isok = true;
    for(int i = 0; i < M; i++){
      isok &= online[i];
      area += (ch[i].x * ch[(i + 1) % M].y - ch[(i + 1) % M].x * ch[i].y);
    }
      
    if(area < EPS)
      cout << "NO" << endl;
    else
      cout << (isok ? "YES" : "NO") << endl;

  }
  return 0;
}
