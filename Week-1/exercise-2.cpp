#include <iostream>
using namespace std;



string LOWER = "abcdefghijklmnopqrstuvwxyz";
string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
string convertString(string s, string mode) {
    for (int letter_1 = 0; letter_1 < s.length(); letter_1++) {
        if (mode == "lower") {
            for (int letter_2 = 0; letter_2 < UPPER.length(); letter_2++) {
                if(s[letter_1] == UPPER[letter_2]) {
                    s[letter_1] = LOWER[letter_2];
                }
            }
        } else {
            for (int letter_2 = 0; letter_2 < LOWER.length(); letter_2++) {
                if(s[letter_1] == LOWER[letter_2]) {
                    s[letter_1] = UPPER[letter_2];
                }
            }
        }
    }
    return s;
}


int main() {
 
    string s; cin >> s;
    cout << convertString(s, "lower") << endl;
    cout << convertString(s, "upper");
   
    return 0;
}