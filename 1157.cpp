#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

const int INF = 1 << 30;
using namespace std;

int F, V;
int A[100][100];
int dp[101][101];

int main(int argc, char **argv){
  //Input
  cin >> F >> V;
  for(int i = 0; i < F; i++)
    for(int j = 0; j < V; j++)
      cin >> A[i][j];

  memset(dp, 0, sizeof(dp));

  //DP
  for(int i = 0; i < F; i++){
    for(int j = i; j < V; j++){
      dp[i + 1][j + 1] = dp[i][j] + A[i][j];
      if(j > i)
	dp[i + 1][j + 1] = max(dp[i + 1][j], 
			       dp[i + 1][j + 1]);
    }
  }

  cout << dp[F][V] << endl;
  return 0;
}