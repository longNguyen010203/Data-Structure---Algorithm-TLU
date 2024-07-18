
#include <iostream>
using namespace std;
 
 
int main() {
 
    unsigned short n; cin >> n;
    unsigned short a[n-1];
    
    for (unsigned short i = 0; i < n-1; i++) {
        cin >> a[i];
    }
 
    for (unsigned short i = 1; i <= n; i++) {
        unsigned short count = 0;
        for (unsigned short j = 0; j < n-1; j++) {
            if (i == a[j]) {
                break;
            }
            count += 1;
        }
        
        if (count == (n-1)) { 
            cout << i; 
            break;
        }
    }
    return 0;
}