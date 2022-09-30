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
#include <cstring>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int num[6];
int dp[120001];


int main(){
  int k = 1;
  while(cin >> num[0] >> num[1] >> num[2] 
	>> num[3] >> num[4] >> num[5]){
    int point = 0;
    for(int i = 1; i <= 6; i++){
      point += (i * num[i - 1]);
    }

    if(point == 0) break;

    if(point % 2 != 0){
      cout << "Collection #" << k << ":" << endl;
      cout << "Can't be divided." << endl;
    }else{
      fill(dp, dp + 120001, -1);
      dp[0] = 0;
      for(int i = 0; i < 6; i++){
	for(int j = 0; j <= point / 2; j++){
	  if(dp[j] >= 0){
	    dp[j] = num[i];
	  }else if(j < (i + 1) || dp[j - (i + 1)] <= 0){
	    dp[j] = -1;
	  }else{
	    dp[j] = dp[j - (i + 1)] - 1;
	  }
	}
      }

      if(dp[point / 2] >= 0){
	cout << "Collection #" << k << ":" << endl;
	cout << "Can be divided." << endl;
      }else{
	cout << "Collection #" << k << ":" << endl;
	cout << "Can't be divided." << endl;
      }
    }
    cout << endl;
    k++;
  }
  return 0;
}
