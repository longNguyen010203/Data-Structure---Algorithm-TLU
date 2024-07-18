#include <iostream>
using namespace std;
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); 
 
    unsigned long long max = 0;
    unsigned int n; cin >> n;
    unsigned long long a[n];
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (max < a[i]) {
            max = a[i];
        }
    } 
    
    cout << max;
 
    return 0;
}