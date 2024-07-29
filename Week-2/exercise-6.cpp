#include <iostream>
using namespace std;



/*
    Biểu thức Modulo ===> O(1)
*/


int main() {

    unsigned int n, m; // O(1)
    cin >> n >> m; // O(1)

    if (n >= 32) { // O(1)
        cout << m; // O(1)
    } else {
        unsigned int mask = (1U << n) - 1; // O(1)
        cout << (m & mask); // O(1)
    }

    return 0; // O(1)
} 
