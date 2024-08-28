#include <iostream>
using namespace std;

/*

    G. Tổng Chữ Số

*/

// Hàm đệ quy để tính tổng các chữ số
int sumDigits(int k, int currentSum = 0) {
    if (k == 0) {
        return currentSum;  // Trường hợp cơ sở: đã đọc hết các chữ số
    }
    
    char digit;
    cin >> digit;  // Đọc một ký tự từ đầu vào
    
    int digitValue = digit - '0';  // Chuyển ký tự thành số
    
    return sumDigits(k - 1, currentSum + digitValue);  // Cộng dồn giá trị số và tiếp tục
}

int main() {
    int k;
    cin >> k;  // Đọc số lượng chữ số
    
    cout << sumDigits(k) << endl;  // In ra tổng các chữ số

    return 0;
}