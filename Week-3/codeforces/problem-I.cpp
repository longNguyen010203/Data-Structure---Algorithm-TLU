#include <iostream>
#include <vector>
using namespace std;
 

const long long OFFSET = 1e9;
 
int main() {
 
    unsigned long long n, q;
    cin >> n >> q;
    vector<bool> check(2*OFFSET+1, false);
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        check[a+OFFSET] = true;
    }

 
    while (q--) {
        long long k; cin >> k;
        if (check[k+OFFSET]) cout << "Yes\n";
        else cout << "No\n";
    }
 
    return 0;
}