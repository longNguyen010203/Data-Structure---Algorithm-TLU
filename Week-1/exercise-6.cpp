#include <iostream>
using namespace std;
 
 
int main() {
 
  unsigned short n; cin >> n;
  unsigned short a[n];
  bool flag = false;
 
  for (unsigned short i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  unsigned short x; cin >> x;
 
  for (unsigned short i = 0; i < n; i++) {
    for (unsigned short j = i; j < n-1; j++) {
      if ((a[i] + a[j+1]) == x) {
        cout << 1; 
        flag = true;
        break;
      }
    }
    if (flag) { break; }
  }
 
  if (!flag) { cout << 0; }
 
  return 0;
}