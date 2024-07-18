#include <iostream>
using namespace std;
 
 
int main() {
 
  unsigned short n; cin >> n;
  unsigned short a[n];
 
  for (unsigned short i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  unsigned short v, u; cin >> v >> u;
  
  for (unsigned short i = n; i > v-1; i--) {
    a[i] = a[i-1];
  }
  a[v-1] = u;
 
  for (unsigned short i = 0; i < n+1; i++) {
    cout << a[i] << " ";
  }
  
  return 0;
}