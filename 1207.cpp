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

int coratts(int n){
  int cnt = 0;
  while(n > 1){
    if(n % 2 != 0) n = 3 * n + 1;
    else n /= 2;
    cnt++;
  }
  return cnt + 1;
}

int main(){
  int a, b;
  while(cin >> a >> b){
    int result = 0;
    cout << a << " " << b << " ";
    if(a > b) swap(a, b);
    for(int i = a; i <= b; i++){
      result = max(result, coratts(i));
    }
    cout << result << endl;
  }
  return 0;
}
