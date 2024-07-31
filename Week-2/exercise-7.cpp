#include <iostream>
using namespace std;
 
 
/*
    So Bi Thieu ===> O(n^2)
*/


 
int main() {
 
    unsigned short n; cin >> n; // O(1)
    unsigned short a[n-1]; // O(1)
    
    for (unsigned short i = 0; i < n-1; i++) { // O(n)
        cin >> a[i]; // O(1)
    }
 
    for (unsigned short i = 1; i <= n; i++) { // O(n)
        unsigned short count = 0; // O(1)
        for (unsigned short j = 0; j < n-1; j++) { // O(n)
            if (i == a[j]) { // O(1)
                break; // O(1)
            }
            count += 1; // O(1)
        }
        
        if (count == (n-1)) {  // O(1)
            cout << i;  // O(1)
            break; // O(1)
        }
    }
    return 0; // O(1)
}