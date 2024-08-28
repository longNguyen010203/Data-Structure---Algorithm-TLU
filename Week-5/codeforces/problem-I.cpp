#include <iostream>
using namespace std;


/*

    I. Tính Tổng

*/


int main() {
    unsigned short n, m;
    cin >> n >> m;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v; cin >> v;
            sum += v;
        }
    }

    cout << sum;

    return 0;
}