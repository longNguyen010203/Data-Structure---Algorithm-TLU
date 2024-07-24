#include <iostream>
using namespace std;


/*
    Kim cương
*/


int main() {

    unsigned short n; cin >> n;
    unsigned short m = n/2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2-i; j++) {
            cout << "*";
        }
        for (int j = 0; j < n/2; j++) {
            cout << "*";
        }
    }


    return 0;
}