
#include <iostream>
#include <math.h>
#include <sstream>
#include <algorithm>
using namespace std;
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;

ll a[100000], sum[100000];
int main(int argc, char **argv){
  a[0] = 1, sum[0] = 1;
  for(int i = 1; i < 100000; i++){
    a[i] = a[i - 1] + floor(log10(10.0 * (i + 1)));
    sum[i] = sum[i - 1] + a[i];
  }

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    //while(n > a[idx]) n -= a[idx++];
    int idx = (int)(lower_bound(sum, sum + 100000, n) - sum);
    //dump(idx);
    n-= idx ? sum[idx - 1] : 0;
    
    idx = 1;
    while(1){
      int keta = floor(log10(10.0 * idx));
      if(n <= keta) break;
      n -= keta;
      idx++;
    }
    stringstream ss; 
    ss << idx;
    string t; ss >> t;
    //cout << idx << " " << n << endl;
    cout << t[n - 1] << endl;
  }
  return 0;
}
