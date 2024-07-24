#include <iostream>
using namespace std;


/*
    Đường đi hình S
*/


int main() {

    unsigned short n, m; cin >> n >> m;
    bool flag = true;
    string direc = "right";

    for (int i = 0; i < n; i++) {
        if (flag) {
            for (int j = 0; j < m; j++) {
                cout << "#";
            } 
            cout << endl;
            flag = false;
        } else {
            if (direc == "right") {
                for (int k = 0; k < m-1; k++) {
                    cout << ".";
                } 
                cout << "#";
                direc = "left";
            } else {
                cout << "#";
                for (int k = 0; k < m-1; k++) {
                    cout << ".";
                } 
                direc = "right";
            }
            cout << endl;
            flag = true;
        }
    }

    return 0;
}