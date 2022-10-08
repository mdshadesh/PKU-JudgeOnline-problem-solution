#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);


int main(int argc, char **argv){
  int c;
  string s;
  while(cin >> c, c){
    cin >> s;

    int beds = 0;
    int leave = 0;
    bool use[26];
    fill(use, use + 26, false);
    for(int i = 0; i < s.length(); i++){
      if(use[s[i] - 'A']){
	use[s[i] - 'A'] = false;
	beds--;
      }else{
	if(c == beds){
	  leave++;
	  continue;
	}
	use[s[i] - 'A'] = true;
	beds++;
      }
    }
    if(leave)
      cout << leave / 2 << " customer(s) walked away." << endl;
    else
      cout << "All customers tanned successfully." << endl;
  }
}
