#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  map<char, int> f;
  map<int, char> t;
  string s = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
  for(int i = 0; i < 26 * 2; i++)
    f[s[i]] = i, t[i] = s[i];

  while(N--){
    char c[14];
    int idx[14];
    scanf("%s", c);
    int len = strlen(c);
    for(int i = 0; i < len; i++) idx[i] = f[c[i]];
    sort(idx, idx + len);

    //set<string> check;
    do{
      for(int i = 0; i < len; i++) c[i] = t[idx[i]];
      printf("%s\n", c);
    }while(next_permutation(idx, idx + len));
  }
  return 0;
}