#include <iostream>
#include <numeric>

using namespace std;

int main(){
  int a[60];
  int n; 
  while(cin >> n, n != 0){
    for(int i = 0; i < n; i++) cin >> a[i];

    bool ok = false;
    for(int i = 0; i < n; i++){
      int c = accumulate(a, a + i, 0);
      int d = accumulate(a + i, a + n, 0);
      if(c == d){
	cout << "Sam stops at position " << i 
	     << " and Ella stops at position " << i + 1 
	     << "." << endl;
	ok = true;
	break;
      }
    }
    if(!ok) cout << "No equal partitioning." << endl;
  }
}