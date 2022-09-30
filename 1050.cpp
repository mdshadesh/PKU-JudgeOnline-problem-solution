#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int dp[130][130];
int table[130][130];
int tmp[130];

int maxSubArr(int *arr, int n){
  int ret = 0, dp = 0;
  for(int i = 0; i < n; i++){
    if(dp < 0) dp = arr[i];
    else{
      dp += arr[i];
      ret = max(ret, dp);
    }
  }
  return ret;
}

int main(){
  int N; cin >> N;
  for(int i = 0; i < N; i++){
     for(int j = 0; j < N; j++){
       cin >> table[i][j];
     } 
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    memset(tmp, 0, sizeof(tmp));
    int onerow = 0;
    for(int j = i; j < N; j++){
      for(int k = 0; k < N; k++) tmp[k] += table[j][k];
      onerow = maxSubArr(tmp, N);
      ans = max(ans, onerow);
    }
  }
  cout << ans << endl;
  return 0;
}