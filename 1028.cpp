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

int main(){
  vector<string> site(1);
  site[0] = "http://www.acm.org/";
  string instruction;
  int index = 0;
  while(cin >> instruction, instruction != "QUIT"){
    string page;
    if(instruction == "VISIT"){
      cin >> page;
      site.erase(site.begin() + index + 1, site.end());
      site.push_back(page);
      index++;
      cout << page << endl;
    }
    if(instruction == "BACK"){
      if(--index < 0){
	index = 0;
	cout << "Ignored" << endl;
      }else
	cout << site[index] << endl;
    }
    if(instruction == "FORWARD"){
      if(++index >= (int)site.size()){
	index = (int)site.size() - 1;
	cout << "Ignored" << endl;
      }else
	cout << site[index] << endl;
    }
  }
  return 0;
}