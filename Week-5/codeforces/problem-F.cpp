#include <iostream>
using namespace std;


/*

    F. A nhân B

*/


// long long mul(int a, int b) {
//     if (b == 1) return a;
//     else return a + mul(a, b-1);
// }


long long mul(int a, int b) {
    if (b == 1) return a;
    if (b % 2 == 0) return mul(a + a, b / 2);
    return a + mul(a, b - 1);
}

int main() {

    int a, b; cin >> a >> b;
    cout << mul(a, b);

    return 0;
}