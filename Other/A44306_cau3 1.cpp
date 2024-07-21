#include <iostream>
using namespace std;

template <class T>
T getAbs(T a) { 
    if (a < 0) return -a;
    return a;
}

int main() {
    int a = 3, b = -3;
    double c = 3.6, d = -3.6;
    cout << getAbs(a) << " " << getAbs(b) << endl;
    cout << getAbs(c) << " " << getAbs(d) << endl;
    return 0;
}