#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

bool lock[101];

int main(){
  int s;
  cin >> s;
  for(int i = 0; i < s; i++){
    int p; cin >> p;

    for(int j = 0; j < 101; j++) lock[j] = false;

    for(int k = 2; k <= p; k++){
      for(int j = k; j <= p; j += k) lock[j] = !lock[j];
    }
    cout << count(lock + 1, lock + p + 1, false) << endl;
  }
  return 0;
}