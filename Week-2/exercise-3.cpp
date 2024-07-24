#include <iostream>
using namespace std;


/*
    Kinh doanh thật dễ 3
*/


int main() {

    unsigned int n; cin >> n;
    short a[n], max, min;

    for  (int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    max = a[0];
    for (int i = 0; i < n; i++) {
        if (max < a[i]) { max = a[i]; }
    }

    min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) { min = a[i]; }
    }

    cout << max-min;

    return 0;
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