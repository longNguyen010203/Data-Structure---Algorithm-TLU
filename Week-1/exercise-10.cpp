#include <iostream>
using namespace std;
 
 
int main() {
 
  unsigned short n; cin >> n;
  unsigned short a[n];
 
  for (unsigned short i = 0; i < n; i++) {
    cin >> a[i];
  }
  unsigned short x; cin >> x;
  
  cout << a[x-1];
  
  return 0;
}