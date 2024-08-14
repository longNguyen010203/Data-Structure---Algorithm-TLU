#include <iostream>
using namespace std;


int main() {

    unsigned int n; cin >> n;
    int k, a[n]; cin >> k;
    bool flag = false;

    for (int i = 0; i < n; i++) cin >> a[i];


    int l = 0, r = n-1;
    while (l <= r) {
        int m = (r+l) / 2;
        if (a[m] == k) {
            cout << "Yes";
            flag = true;
            break;
        } else if (a[m] < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if (!flag) { cout << "No"; }

    return 0;
}