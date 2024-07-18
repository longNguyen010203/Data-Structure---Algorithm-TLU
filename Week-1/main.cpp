#include <iostream>
using namespace std;


#include <iostream>
using namespace std;
 
 
int main() {
 
    unsigned short n, m; cin >> n >> m;
    unsigned short a[n], b[m];
    bool flag = true;
    unsigned short x;
   
    for (unsigned short i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (unsigned short i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (unsigned short i = 0; i < n; i++) {
        for (unsigned short j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                flag = false;
                x = a[i];
                break;
            }
        }
 
    }
 
    if (flag) { cout << "None"; }
   
    return 0;
}