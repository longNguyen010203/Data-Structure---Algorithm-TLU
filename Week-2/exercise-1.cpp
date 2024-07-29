#include <iostream>
using namespace std;


/*
    Đường đi hình S ===> O(n^2)
*/


int main() {

    unsigned short n, m; cin >> n >> m; // O(1)
    bool flag = true; // O(1)
    string direc = "right"; // O(1)

    for (int i = 0; i < n; i++) { // O(n)
        if (flag) { // O(1)
            for (int j = 0; j < m; j++) { // O(n)
                cout << "#"; // O(1)
            } 
            cout << endl; // O(1)
            flag = false; // O(1)
        } else {
            if (direc == "right") { // O(1)
                for (int k = 0; k < m-1; k++) { // O(n)
                    cout << "."; // O(1)
                } 
                cout << "#"; // O(1)
                direc = "left"; // O(1)
            } else { 
                cout << "#"; // O(1)
                for (int k = 0; k < m-1 ; k++) { // O(n)
                    cout << "."; // O(1)
                } 
                direc = "right"; // O(1)
            }
            cout << endl; // O(1)
            flag = true; // O(1)
        }
    }

    return 0; // O(1)
}