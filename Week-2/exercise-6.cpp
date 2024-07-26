#include <iostream>
using namespace std;



/*
    Biểu thức Modulo
*/


int main() {

    unsigned int n, m;
    cin >> n >> m;

    if (n >= 32) {
        cout << m;
    } else {
        unsigned int mask = (1U << n) - 1;
        cout << (m & mask);
    }

    return 0;
}
