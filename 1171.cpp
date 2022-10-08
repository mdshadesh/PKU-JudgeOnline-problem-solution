
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
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

struct str{
  int L, point;
  char s[10];
}word[40010];

int sc[] = {7,6,1,2,2,5,4,1,3,5,2,1,4,6,5,5,7,6,3,7,7,4,6,5,2,5};
char key[] = {"qwertyuiopasdfghjklzxcvbnm"};
int po[0xff];

bool comp(str s, str t){
  if(s.L != t.L) return s.L < t.L;
  return s.point < t.point;
}

int main(int argc, char **argv){
  for(int i = 0; i < 26; i++)
    po[key[i]] = sc[i];
  

  int p = 0;
  char s[8];
  gets(s);
  int mag[26] = {0};
  int L = strlen(s);
  for(int i = 0; i < L; i++){
    mag[s[i] - 'a']++;
    p += po[s[i]];
  }

  int ans = 0, idx = 0;
  while(gets(s)){
    if(s[0] == '.') break;
    if(L < strlen(s)) continue;

    int ptmp = 0;

    int mag2[26];
    memcpy(mag2, mag, 26 * sizeof(int));
    for(int i = 0; i < strlen(s); i++){
      ptmp += po[s[i]];
      mag2[s[i] - 'a']--;
    }
    
    bool check = true;
    for(int i = 0; i < 26; i++)
      check &= (mag2[i] >= 0);
    
    if(!check) continue;
    ans = max(ans, ptmp);
    

    word[idx].L = strlen(s);
    word[idx].point = ptmp;
    memcpy(word[idx].s, s, sizeof(s));
    idx++;
  }

  sort(word, word + idx, comp);
  for(int i = 0; i < idx; i++){
    if(word[i].L * 2 > L) break;
    for(int j = i + 1; j < idx; j++){
      if(word[i].L + word[j].L > L) break;
      if(word[i].point + word[j].point > p) break;

      
      int mag2[26];
      memcpy(mag2, mag, 26 * sizeof(int));
      for(int k = 0; k < word[i].L; k++) mag2[word[i].s[k] - 'a']--;      
      for(int k = 0; k < word[j].L; k++) mag2[word[j].s[k] - 'a']--;      
      bool check = true;
      for(int k = 0; k < 26; k++) check &= (mag2[k] >= 0);
      if(check){
	ans = max(ans, word[i].point + word[j].point);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
