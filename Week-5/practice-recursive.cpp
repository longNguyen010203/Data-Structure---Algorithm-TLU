#include <iostream>
#include <string>
using namespace std;


// 1. Tính tổng các số chẵn trong mảng
int sumEven(int a[], int size) {
    if (size == 0) return 0;
    if (a[size-1] % 2 == 0) return a[size-1] + sumEven(a, size-1);
    else return sumEven(a, size-1);
}

// 2. Hàm printReverse() để in ngược mảng trong Slist
template <class E> 
struct Node{
    E data;
    Node<E> *next;
    Node(E e = E() , Node<E> *l = NULL)
    : data(e), next(l) {}
};

template <class E> 
class Slist{
    protected:
        Node<E> *head;
        int size;
    public:
        Slist(): head(NULL), size(0) {}
        int getSize() const { return size; }
        bool isEmpty() const{ return size == 0; }
        void print() const {
            Node<E> * tmp = head; 
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }


        void printReverseHelper(Node<E> *node) const {
            if (node == NULL) return;
            printReverseHelper(node->next);
            cout << node->data << " ";
        }
        void printReverse() const {
            printReverseHelper(head);
        }
};

// 3. Kiểm tra số nguyên n có phải số nguyên tố
bool isPrime(int n, int m = -1) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (m == -1) m = n / 2;
    if (m == 1) return true;
    if (n % m == 0) return false;
    else return isPrime(n, m-1);
}

// 4. Hàm đệ quy để chuyển đỗi một chuỗi chứ số thành một số nguyên
int convertStringtoInteger(string s, int res=0) {
    int size = s.length();
    if (size == 0) return res;
    else {
        res  = res*10 + (s[0] - '0');
        return convertStringtoInteger(s.substr(1), res);
    }
}


// 5. Hàm tính số lượng ước của số nguyên n 
int countUoc(int n, int m = -1) { // => Hàm này chỉ đếm số lượng ước cho số nguyên dương
    if (n == 0) {
        cout << "Vo So"; return -1;
    }
    if (n == 1) return 1;
    if (m == -1) m = n;
    if (m == 1) return 1;
    if (n % m == 0) return 1 + countUoc(n, m-1);
    else return countUoc(n, m-1);
}

// 6. Hàm tính ucln của a,b theo euclid
int getUCLN(int a, int b) {
    if (b == 0) return a;
    else return getUCLN(b, a%b);
}


int main() {
    string s = "123456";
    int a[] = {1, 2, 3, 4, 5, 6};
    cout << sumEven(a, 6) << endl;
    cout << isPrime(11) << endl;
    cout << countUoc(15) << endl;
    cout << getUCLN(2, 3) << endl;
    cout << convertStringtoInteger(s) << endl;

    return 0;
}