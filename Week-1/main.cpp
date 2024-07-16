#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int ROWS = 3;
int COLUMNS = 3;


int main() {

    int matrix[ROWS][COLUMNS] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 4}
    };

    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            cout << matrix[row][column] << " ";
        } cout << endl;
    }

    return 0;
}