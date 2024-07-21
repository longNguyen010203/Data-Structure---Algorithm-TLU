#include <iostream>
#include <variant>
#include <string>
using namespace std;



void insertElement(int size, int list[], int location, int val) {
    for (int i = size; i > location-1; i--) {
        list[i] = list[i-1];
    } list[location-1] = val;
}

void removeElement(int size, int list[], int location) {
    for (int i = location-1; i < size-1; i++) {
        list[i] = list[i+1];
    }
} 

int countElement(int size, int list[], int val) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (val == list[i]) {
            count++;
        }
    } return count;
}

int selectMin(int size, int list[]) {
    int min = list[0];
    for (int i = 0; i < size; i++) {
        if (min > list[i]) { min = list[i]; }
    } return min;
}

int selectMax(int size, int list[]) {
    int max = list[0];
    for (int i = 0; i < size; i++) {
        if (max < list[i]) { max = list[i]; }
    } return max;
}

variant<int, string> searchElement(int size, int list[], int val, int start = 0) {
    for (int i = start; i < size; i++) {
        if (val == list[i]) { return list[i]; }
        else { return "NOT FOUND"; }
    }
}

bool checkUnique(int size, int list[], int val) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == val) { count++; }
        if (count >= 2) { return false; }
    } return true;
}





int main() {

    int size = 10;
    int LIST[size] = {456, 2003, -345, 2003, -234, 0, 2003, 272, 101, -1};
    
    cout << checkUnique(size, LIST, 456);

    // for (int i = 0; i < size-1; i++) {
    //     cout << LIST[i] << " ";
    // }

    return 0;
}

