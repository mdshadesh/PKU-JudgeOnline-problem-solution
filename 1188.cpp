
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()

const int INF = 1 << 29;
const double EPS = 1e-7;

int main(int argc, char **argv){
  int N;
  while(cin >> N, N){
    int lx = -INF, rx = INF;
    int ly = -INF, ry = INF;
    int lz = -INF, rz = INF;
    for(int i = 0; i < N; i++){
      int x, y, z, d;
      cin >> x >> y >> z >> d;
      lx = max(lx, x);
      rx = min(rx, x + d);
      ly = max(ly, y);
      ry = min(ry, y + d);
      lz = max(lz, z);
      rz = min(rz, z + d);
    }
    if(rx < lx || ry < ly || rz < lz) 
      cout << 0 << endl;
    else
      cout << -(lx - rx) * (ly - ry) * (lz - rz) << endl;
  }
}