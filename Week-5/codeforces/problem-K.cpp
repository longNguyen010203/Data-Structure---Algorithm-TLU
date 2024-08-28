#include <iostream>
using namespace std;


/*

    K. Timf số lớn 1

*/

// long long max(long long a, long long b) {
//     return (a > b) ? a : b;
// }

// long long findMax(long long a[], int n) {
//     if (n == 1) return a[0];
//     else return max(a[n-1], findMax(a, n-1));
// }

int main() {

    unsigned int n; cin >> n;

    long long max = 0;
    for (int i = 0; i < n; i++) {
        long long num; cin >> num;
        if (max < num) max = num;
    }
    // cout << findMax(a, n);
    cout << max;

    return 0;
}