#include<iostream>
using namespace std;


/*
    Số may mắn ===> O(n)
*/


 
int main()
{
    unsigned long long n; cin >> n; // O(1)
    unsigned short du, count = 0; // O(1)
    while (n != 0) { // O(n)
        du = n % 10; // O(1)
        n = n / 10; // O(1)
        if (du == 4 || du == 7) { // O(1)
            count++; // O(1)
        }
    } // ==> O(n)

    if (count == 4 || count ==7) { // O(1)
        cout << "YES"; // O(1)
    } else {
        cout << "NO"; // O(1)
    }
    
    return 0; // O(1)
}