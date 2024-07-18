#include <iostream>
using namespace std;



int main() {

    unsigned short n, size; cin >> n;
    string word[n];
    for (int i = 0; i < n; i++) {
        cin >> word[i];
    }

    for (int i = 0; i < n; i++) {
        size = word[i].length();

        if (size <= 10) {
            cout << word[i] << endl;
        } else {
            cout << word[i][0] << size-2 << word[i][size-1];
            cout << endl;
        }
    }

    return 0;
}