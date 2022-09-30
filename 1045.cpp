#include <math.h>
#include <cstdio>
using namespace std;
int main(){
  double V, R, C;
  int n;
  scanf("%lf %lf %lf %d", &V, &R, &C, &n);
  while(n--){
    double w;
    scanf("%lf", &w);
    double res = C * R * w * V / sqrt(1 + C * C * R * R * w * w);
    printf("%.3lf\n", res);
  }
  return 0;
}