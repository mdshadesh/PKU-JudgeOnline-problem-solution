#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string decode(string a){
  string b;
  int N = a.length();
  for(int i = 0; i < N; i++){
    if('A' <= a[i] && a[i] <= 'C') b += '2';
    else if('D' <= a[i] && a[i] <= 'F') b += '3';
    else if('G' <= a[i] && a[i] <= 'I') b += '4';
    else if('J' <= a[i] && a[i] <= 'L') b += '5';
    else if('M' <= a[i] && a[i] <= 'O') b += '6';
    else if('P' <= a[i] && a[i] <= 'S') b += '7';
    else if('T' <= a[i] && a[i] <= 'V') b += '8';
    else if('W' <= a[i] && a[i] <= 'Y') b += '9';
    else b += a[i];
  }
  return b;
}

int main(int argc, char **argv){
  int n;
  map<string, int> mp;
  cin >> n;
  for(int i = 0; i < n; i++){
    string t, s;
    cin >> t;
    int N = t.length();
    for(int j = 0; j < N; j++) if(t[j] != ' ' && t[j] != '-') s += t[j];
    mp[decode(s)]++;
  }

  bool found = false;
  for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
    if(it -> second != 1){
      string u = it -> first;
      u = u.substr(0, 3) + '-' + u.substr(3, 4);
      cout << u << " " << it -> second << endl;
        found = true;
    }
  }
  if(!found) cout << "No duplicates." << endl;
  return 0;
}