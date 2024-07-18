#include <iostream>
#include <set>
using namespace std;
 
 
int main() {
 
    unsigned short n, m; cin >> n >> m;
    unsigned short a[n], b[m], c[n];
    bool flag = true;
    unsigned short index = 0;
    set<unsigned short> s;
   
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
                c[index] = a[i];
                index++;
                break;
            }
        }
 
    }
 
    if (flag) { cout << "None"; }

    if (!flag) {
        for (unsigned short i = 0; i < index; i++) {
            for(unsigned short j = i+1; j < index; j++) { 
                if (c[i] > c[j]) {
                    unsigned short temp = c[i];
                    c[i] = c[j];
                    c[j] = temp;
                }
            }
        }
        for (unsigned short i = 0; i < index; i++) {
            // cout << c[i] << " ";
            s.insert(c[i]);
        }
        for (unsigned short e: s) { cout << e << " "; }
    }
   
    return 0;
}