
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


map<char, string> mo;
map<string, char> invmo;


int main(int argc, char **argv){
  mo['A'] = ".-";  mo['B'] = "-...";  mo['C'] = "-.-.";
  mo['D'] = "-..";  mo['E'] = ".";  mo['F'] = "..-.";
  mo['G'] = "--.";  mo['H'] = "....";  mo['I'] = "..";
  mo['J'] = ".---";  mo['K'] = "-.-";  mo['L'] = ".-..";
  mo['M'] = "--";  mo['N'] = "-.";  mo['O'] = "---";
  mo['P'] = ".--.";  mo['Q'] = "--.-";  mo['R'] = ".-.";
  mo['S'] = "...";  mo['T'] = "-";  mo['U'] = "..-";
  mo['V'] = "...-";  mo['W'] = ".--";  mo['X'] = "-..-";
  mo['Y'] = "-.--";  mo['Z'] = "--..";  mo['_'] = "..--";
  mo['.'] = "---.";  mo[','] = ".-.-";  mo['?'] = "----";

  map<char, string>::iterator it = mo.begin();
  for(; it != mo.end(); it++) invmo[it->second] = it->first;

  int N;
  cin >> N;
  for(int k = 0; k < N; k++){
    string s;
    cin >> s;
    vector<int> num;
    string morse;
    for(int i = 0; i < s.size(); i++){
      morse += mo[s[i]];
      num.push_back(mo[s[i]].size());
    }
    reverse(ALL(num));

    cout << k + 1 << ": ";

    int pos = 0;
    for(int i = 0; i < num.size(); i++){
      cout << invmo[morse.substr(pos, num[i])];
      pos += num[i];
    }
    cout << endl;
  }
  return 0;
}
