#include <iostream>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned int n; cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    cout << abs(sum);
    
    return 0;
}