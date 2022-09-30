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
#include <cstring>
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

int mat[5][5] = {
  5, -1, -2, -1, -3, 
  -1, 5, -3, -2, -4,  
  -2, -3, 5, -2, -2,
  -1, -2, -2, 5, -1, 
  -3, -4, -2, -1, 0,
};

int dp[101][101];

int main(){
  int n;
  cin >> n;
  map<char, int> dic;
  dic['A'] = 0;  dic['C'] = 1;  dic['G'] = 2;  
  dic['T'] = 3;  dic['-'] = 4;

  while(n--){
    int L, M;
    string s, t;
    cin >> L >> s;
    cin >> M >> t;

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < L; i++)
      dp[i + 1][0] = dp[i][0] + mat[dic[s[i]]][dic['-']];
    for(int i = 0; i < M; i++)
      dp[0][i + 1] = dp[0][i] + mat[dic['-']][dic[t[i]]];

    for(int i = 0; i < L; i++){
      for(int j = 0; j < M; j++){
	if(s[i] == t[j]){
	 
	  dp[i + 1][j + 1] = dp[i][j] + mat[dic[s[i]]][dic[t[j]]];
	}else{
	 
	  dp[i + 1][j + 1] = max(dp[i + 1][j] + mat[dic['-']][dic[t[j]]],
				     max(dp[i][j + 1] + mat[dic[s[i]]][dic['-']],
					 dp[i][j] + mat[dic[s[i]]][dic[t[j]]]));

	}
      }
    }
    cout << dp[L][M] << endl;
  }
  return 0;
}