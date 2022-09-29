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
  double a;
  double sum = 0.0;
  for(int i = 0; i < 12; i++){
    scanf("%lf", &a);
    sum += a;
  }
  sum /= 12;
  sum *= 100;
  int dst = (int)(sum + 0.5);
  printf("$%.2lf", (double)dst / 100.0);
  return 0;
}