
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

int dy[] = {1, 0, 0, -1};//NEWS
int dx[] = {0, 1, -1, 0};
int by[] = {-1, -1, 0, 0};
int bx[] = {0, -1, 0, -1};

char f[70][70];

int main(int argc, char **argv){
  map<char, int> m, b;
  m['N'] = 0, m['E'] = 1, m['W'] = 2, m['S'] = 3;
  int T; cin >> T;
  for(int t = 1; t <= T; t++){
    FILL(f, '.');
    int cx, cy;
    string dir;
    cin >> cx >> cy;
    cin >> dir;

    for(int i = 0; i < dir.size() - 1; i++){
      cy += dy[m[dir[i]]];
      cx += dx[m[dir[i]]];
      f[cy + by[m[dir[i]]]][cx + bx[m[dir[i]]]] = 'X';
    }
    cout << "Bitmap #" << t << endl;
    for(int i = 31; i >= 0; i--){
      for(int j = 0; j < 32; j++)
	cout << f[i][j];
      cout << endl;
    }
    cout << endl;
  }
  
  return 0;
}
