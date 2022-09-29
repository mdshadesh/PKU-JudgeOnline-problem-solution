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

const double PI = 3.141592653;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    double x, y;
    cin >> x >> y;
    double l = sqrt(x * x + y * y);
    cout << "Property " << i + 1 
	 << ": This property will begin eroding in year "
	 << ceil(l * l * PI / 100.0) << "." << endl;
  }
  cout << "END OF OUTPUT." << endl;
  return 0;
}