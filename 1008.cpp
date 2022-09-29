// Time-stamp: <Fri Dec 23 01:32:11 東京 (標準時) 2016>
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
string haab[] = {
  "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet",
};
string tzolkin[] = {
  "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau",
};
int main(int argc, char **argv){
  map<int, string> tz_encode;
  for(int i = 0; i < 260; i++){
    stringstream ss;
    ss << (i % 13 + 1);
    tz_encode[i] = ss.str() + " " + tzolkin[i % 20];
  }

  int T; scanf("%d", &T);
  printf("%d\n", T);
  for(int t = 0; t < T; t++){
    int day, year;
    char mon[10];
    scanf("%d. %s %d", &day, mon, &year);
    
    int v = 365 * year + (find(haab, haab + 19, string(mon)) - haab) * 20 + day;
    printf("%s %d\n", tz_encode[v % 260].c_str(), v / 260);
  }
  return 0;
}
