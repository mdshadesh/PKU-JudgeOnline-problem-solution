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

int main(){
  int p[6];
  while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5]){
    if(p[0] + p[1] + p[2] + p[3] + p[4] + p[5] == 0) break;
    int num = 0;
    int s1 = 0;
    int s2 = 0;

    //6
    num += p[5];
    
    //5
    num += p[4];
    s1 += 11 * p[4];

    //4
    num += p[3];
    s2 += 5 * p[3];

    //3
    num += (p[2] + 3) / 4;
    switch(p[2] % 4){
    case 0:
      s1 += 0; s2 += 0; break;
    case 1:
      s1 += 7; s2 += 5; break;
    case 2:
      s1 += 6; s2 += 3; break;
    case 3:
      s1 += 5; s2 += 1; break;
    }

    //2
    if(s2 < p[1]) p[1] -= s2;
    else{
      s1 += (s2 - p[1]) * 4;
      p[1] = 0;
    }
    num += (p[1] + 8) / 9;
    s1 += (9 - p[1] % 9) % 9 * 4;
    
    //1
    p[0] -= min(s1, p[0]);
    num += (p[0] + 35) / 36;
    cout << num  << endl;
  }
  return 0;
}