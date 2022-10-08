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

struct team{
  string name;
  int t[7];
  int ac, sum, mean;

  bool operator<(const team &r)const{
    if(ac == r.ac){
      if(sum == r.sum){
	if(mean == r.mean) return name < r.name;
	else return mean < r.mean;
      }else return sum < r.sum;
    }else return ac > r.ac;
  }
};

int main(){
  int N, idx = 0;
  while(cin >> N, N){
    vector<team> p(N);
    for(int i = 0; i < N; i++){
      cin >> p[i].name;

      int ac = 0, sum = 0;
      double tmp = 0.0;
      for(int j = 0; j < 7; j++){
	cin >> p[i].t[j];
	if(p[i].t[j]){
	  ac++;
	  sum += p[i].t[j];
	  tmp += log(p[i].t[j]);
	}
      }
      p[i].ac = ac;
      p[i].sum = sum;
      
      if(ac){
	tmp /= ac;
	p[i].mean = exp(tmp) + 0.5;
      }else p[i].mean = 0;
    }
    sort(ALL(p));

    printf("CONTEST %d\n", ++idx);
    
    int prank = 0, rank;
    for(int i = 0; i < N; i++){
      if(i > 0 &&
	 p[i - 1].ac == p[i].ac &&
	 p[i - 1].sum == p[i].sum &&
	 p[i - 1].mean == p[i].mean){
	rank = prank;
      }else{
	rank = i;
      }
      prank = rank;
      printf("%02d %-10s %d %4d %3d %3d %3d %3d %3d %3d %3d %3d\n",
	     rank + 1, p[i].name.c_str(), p[i].ac, p[i].sum, p[i].mean,
	     p[i].t[0], p[i].t[1], p[i].t[2], p[i].t[3],
	     p[i].t[4], p[i].t[5], p[i].t[6]);
    }
  }
  return 0;
}
