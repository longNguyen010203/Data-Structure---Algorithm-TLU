#include <iostream>
using namespace std;


/*

    A. fibonaci

*/


// Hàm đệ quy để tính F(n) theo định nghĩa Fibonacci đã cho
long long fib(long long n) {
    if (n == 0) return 0;       // Trường hợp cơ sở: F(0) = 0
    if (n == 1) return 1;       // Trường hợp cơ sở: F(1) = 1
    
    if (n % 2 == 0) {
        return fib(n / 2);  // Nếu n chẵn: F(2 * n) = F(n)
    } else {
        long long h = (n - 1) / 2;
        return fib(h) + fib(h + 1);  // Nếu n lẻ: F(2 * n + 1) = F(n) + F(n + 1)
    }
}

int main() {
    long long n;
    cin >> n;  // Đọc giá trị của n
    
    cout << fib(n) << endl;  // Tính và in kết quả của F(n)

    return 0;
}