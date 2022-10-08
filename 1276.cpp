#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int dp[100001];
int Dk[11], Nk[11];

int main(int argc, char **argv){
  int cash;
  while(cin >> cash){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> Nk[i] >> Dk[i];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= cash; j++){
	if(dp[j] >= 0){
	  dp[j] = Nk[i];
	}else if(j < Dk[i] || dp[j - Dk[i]] <= 0){
	  dp[j] = -1;
	}else{
	  dp[j] = dp[j - Dk[i]] - 1;
	}
      }
    }
    int ans;
    for(ans = cash; ans >= 0; ans--){
      if(dp[ans] >= 0) break;
    }
    cout << ans << endl;
  }
  return 0;
}