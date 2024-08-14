#include <iostream>
using namespace std;


int main() {

    unsigned short t, n; cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        unsigned short a[n];
        for (int j = 0; j < n; j++) cin >> a[j];

        for (int k = 0; k < n; k++) {
            if (a[k] != a[k+1] && a[k] != a[k+2]) {
                cout << k+1 << endl; break;
            } else if (a[k+1] != a[k] && a[k+1] != a[k+2]) {
                cout << k+2 << endl; break;
            } else if (a[k+2] != a[k] && a[k+2] != a[k+1]) { 
                cout << k+3 << endl; break; 
            }
        }
    }

    return 0;
}