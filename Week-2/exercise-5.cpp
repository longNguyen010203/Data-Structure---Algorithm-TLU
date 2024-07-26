#include<iostream>
using namespace std;


/*
    Số may mắn
*/


 
int main()
{
    unsigned long long n; cin >> n;
    unsigned short du, count = 0;
    while (n != 0) {
        du = n % 10;
        n = n / 10;
        if (du == 4 || du == 7) {
            count++;
        }
    }
    if (count == 4 || count ==7) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}