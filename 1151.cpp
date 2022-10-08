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

struct rect{
  double x1, y1, x2, y2;
  bool operator<(const rect &r) const {
    return y1 < r.y1;
  }
};

int main(){
  int T;
  for(int t = 0; ; t++){
    int N;
    cin >> N;
    if(N == 0) break;
    
    vector<rect> rs;
    vector<double> xs;
    for(int i = 0; i < N; i++){
      rect tmp;
      cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
      rs.push_back(tmp);
      xs.push_back(tmp.x1);
      xs.push_back(tmp.x2);
    }
    sort(ALL(rs));
    sort(ALL(xs));

    //vector<rect>::
    double ans = 0.0;
    for(int i = 0; i < xs.size() - 1; i++){
      double w = xs[i + 1] - xs[i];
      //dump(w);

      double lb = -1e10, ub = -1e10;
      for(int j = 0; j < N; j++){
	if(rs[j].x1 - EPS < xs[i] && xs[i + 1] < rs[j].x2 + EPS){
	  if(ub + EPS < rs[j].y1){
	    //dump(ub-lb);
	    ans += w * (ub - lb);
	    lb = rs[j].y1;
	    ub = rs[j].y2;
	  }else{
	    ub = max(ub, rs[j].y2);
	  }
	}
      }
      //dump(ub-lb);
      ans += w * (ub - lb);
    }
    printf("Test case #%d\n", t + 1);
    printf("Total explored area: %.2f\n\n", ans);
  }
  return 0;
}
