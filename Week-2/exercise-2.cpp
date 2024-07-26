#include <iostream>
using namespace std;


/*
    Kim cương
*/


int main() {

    unsigned short n; cin >> n;
    unsigned short s = n/2;
    unsigned short d = 1;

    for (int i = 0; i < n/2+1; i++) {
        for (int j = 0; j < s; j++) { cout << "*"; }
        for (int j = 0; j < d; j++) { cout << "D"; }
        for (int j = 0; j < s; j++) { cout << "*";}
        cout << endl;
        if (s == 0 && d == n) { break; } 
        else { s -= 1; d += 2; }
    }

    for (int i = 0; i < n/2; i++) {
        s += 1; d -= 2;
        for (int j = 0; j < s; j++) { cout << "*"; }
        for (int j = 0; j < d; j++) { cout << "D"; }
        for (int j = 0; j < s; j++) { cout << "*";}
        cout << endl;
    }

    return 0;
}