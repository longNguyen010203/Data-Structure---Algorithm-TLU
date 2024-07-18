#include <iostream>
using namespace std;
 
 
int main() {
 
  unsigned short n; cin >> n;
  unsigned short a[n];
 
  for (unsigned short i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  unsigned short k; cin >> k;
 
  for (unsigned short i = k-1; i < n-1; i++) {
    a[i] = a[i+1];
  }
 
  for (unsigned short i = 0; i < n-1; i++) {
    cout << a[i] << " ";
  }
  
  return 0;
}