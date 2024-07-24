#include <iostream>
using namespace std;


/*
    PanGRAM
*/


int main() {

    unsigned short n; cin >> n;
    string s, r; cin >> s;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }

    for (int i = 97; i <= 122; i++) {
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            if (i == c) {
                flag = true;
                break;
            } else { flag = false; }
        }
        if (!flag) {
            cout << "NO";
            break; 
        }
    }

    if (flag) { cout << "YES"; }


    return 0;
}