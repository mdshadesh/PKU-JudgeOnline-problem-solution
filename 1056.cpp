
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

int main(int argc, char **argv){
  int idx = 0;
  while(1){
    string s;
    vector<string> p;
    while(1){
      cin >> s;
      if(cin.eof()) goto L1;
      if(s == "9") break;
      p.push_back(s);
    }
    
    idx++;
    int N = p.size();
    bool check = true;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	if(i != j && p[i] == p[j].substr(0, p[i].length()))
	  check = false;

    if(check) cout << "Set " << idx << " is immediately decodable" << endl;
    else cout << "Set " << idx <<  " is not immediately decodable" << endl;
  }
 L1:;
  return 0;
}