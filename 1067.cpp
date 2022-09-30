#include <algorithm>
#include <iostream>
#include <cmath>

typedef long long ll;

using namespace std;

int main(int argc, char **argv){
  ll m, n;
  while(cin >> m >> n){
    if(n > m) swap(n, m);
    if(m == n) cout << 1 << endl;
    else{
      ll q = (ll)floor((double)((m - n) * (1.0 + sqrt(5)) / 2.0));
      cout << (q != n) << endl;
    }
  }
  return 0;
}
