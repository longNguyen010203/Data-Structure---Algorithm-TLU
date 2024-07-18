#include <iostream>
using namespace std;
 
 
int main() {
 
  unsigned short n, m; cin >> n >> m;
  short matrix[n][m]; int sum = 0;
  
  for (unsigned short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      cin >> matrix[i][j];
      sum += matrix[i][j];
    }
  }
 
  cout << sum;
  
  return 0;
}