#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    unsigned long long n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++) {
        int l = 0, r = a.size();
        while (l < r) {
            int mid = (l+r) / 2;
            if (a[mid] <= b[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        } 
        cout << l << " ";
    }

    return 0;
}