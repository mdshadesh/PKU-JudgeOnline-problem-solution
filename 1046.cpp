#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
//const int MAX_N = ;

int col[3][16];

int main()
{
  for(int i = 0; i < 16; i++) cin >> col[0][i] >> col[1][i] >> col[2][i];
  int r, g, b;
  while(cin >> r >> g >> b){
    if(r == -1 && g == -1 && b == -1) break;
    int index;
    int tmp = 100000000;
    for(int i = 0; i < 16; i++){
      int dist =
        (col[0][i] - r) * (col[0][i] - r)
          + (col[1][i] - g) * (col[1][i] - g)
            + (col[2][i] - b) * (col[2][i] - b);
      if(tmp > dist){
        tmp = dist;
        index = i;
      }
    }
    cout << "(" << r << "," << g << "," << b << ") maps to "
      << "(" << col[0][index] << "," << col[1][index] << "," << col[2][index] << ")" << endl;
  }
  return 0;
}