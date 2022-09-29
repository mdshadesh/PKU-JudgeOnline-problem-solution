#include <iostream>
#include <math.h>
using namespace std;

int main(){
  double a;
  while(cin >> a){
    if(a < 0.01) break;
    double sum = 0.0;
    int i = 2;
    while(sum < a){
      sum += (1.0 / i);
      i++;
    }
    cout << i - 2 << " card(s)" << endl;
  }
  return 0;
}