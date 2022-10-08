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

string caesar(string a){
  int N = a.length();
  string sss;
  for(int i = 0; i < N; i++){
    if('A' <= a[i] && a[i] <= 'Z'){
	sss += (char)((a[i] - 'A' + 21) % 26 + 'A');
    }else{
      sss += a[i];
    }
  }
  return sss;
}

int main(){
  string st;
  for(;;){
    getline(cin, st);
    if(st == "ENDOFINPUT") break;
    getline(cin, st);
    cout << caesar(st) << endl;
    getline(cin, st);
  }
  return 0;
}
