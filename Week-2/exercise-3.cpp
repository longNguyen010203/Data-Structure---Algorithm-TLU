#include <iostream>
using namespace std;


/*
    Kinh doanh thật dễ 3 ====> O(n)
*/


int main() {

    unsigned int n; cin >> n; // O(1)
    short a[n], max, min; // O(1)

    for  (int i = 0; i < n; i++) {
        cin >> a[i];
    } // ==> O(n)

    max = a[0]; // O(1)
    for (int i = 0; i < n; i++) { // O(n)
        if (max < a[i]) { max = a[i]; } // O(1)
    } // ==> O(n)

    min = a[0]; // O(1)
    for (int i = 0; i < n; i++) { // O(n)
        if (min > a[i]) { min = a[i]; } // O(1)
    } // ==> O(n)

    cout << max-min; // O(1)

    return 0; // O(1)
} 




// int main() {

//     unsigned int n; cin >> n;
//     short a[n], MaxDiff, difference;

//     for  (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }    
    
//     MaxDiff = a[0] - a[1];
//     if (MaxDiff < 0) { MaxDiff = MaxDiff * (-1); }

//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             difference = a[i] - a[j];
//             if (difference < 0) { difference = difference * (-1); }

//             if (MaxDiff < difference) {
//                 MaxDiff = difference;
//             }
//         }
//     }

//     cout << MaxDiff;

//     return 0;
// }