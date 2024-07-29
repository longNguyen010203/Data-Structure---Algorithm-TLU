#include <iostream>
#include <cmath>
using namespace std;



template <typename E>

class AList {
    protected:
        int maxSize;
        int size;
        E *list;

    public:
        AList(int maxSize = 100) {
            this->size = 0;
            this->maxSize = maxSize;
            list = new E[maxSize];
        } // ==> O(1)

        int getSize() const { return size; } // ==> O(1)
        bool isEmpty() const { return size == 0; } // ==> O(1)
        bool isFull() const { return size == maxSize; } // ==> O(1)

        bool find(const E &e) const {
            for (int i = 0; i < size; i++) {
                if (e == list[i]) {
                    return true;
                }
            }
            return false;
        } // ==> O(n)

        bool isPrime(const E &value) const {
            if (value < 2) return false;
            for (int i = 2; i <= sqrt(value); i++) {
                if (value % i == 0) {
                    return false;
                } 
            }
            return true;
        } // ==> O(logn)

        E getSum() const {
            if (isEmpty()) { throw "List is Empty"; }

            E sum = 0;
            for (int i = 0; i < size; i++) {
                sum += list[i];
            }
            return sum;
        } // ==> O(n)

        void printEven() const {
            if (isEmpty()) { throw "List is Empty"; }
            bool flag = true;

            for (int i = 0; i < size; i++) {
                if (list[i] % 2 == 0) {
                    cout << list[i] << " ";
                    flag = false;
                }
            }
            if (flag) { cout << "haven't even element"; }
        } // ==> O(n)

        void addFirst(const E &value) {
            if (isFull()) { throw "List is full"; }
            if (isEmpty()) { list[0] = value; }
            else {
                for (int j = size; j >= 1; j--) {
                    list[j] = list[j - 1];
                }
                list[0] = value;
                size++;
            } 
        } // ==> O(n)

        void removeLast() {
            if (isEmpty()) { throw "List is Empty"; }
            size--;
        } // ==> O(1)

        int countValue(const E &value) const {
            if (isEmpty()) { throw "List is Empty"; }
            if (!find(value)) { throw "Element Not Exists"; }

            int count = 0;
            for (int i = 0; i < size; i++) {
                if (value == list[i]) { count++; }
            }
            return count;
        } // ==> O(n)

        int countPrime() const {
            if (isEmpty()) { throw "List is Empty"; }

            int count = 0;
            for (int i = 0; i < size; i++) {
                if (isPrime(list[i])) {
                    count++;
                } 
            }
            return count;
        } // ==> O(nlogn)

        E getMin() const {
            if (isEmpty()) { throw "List is Empty"; }

            E min = list[0];
            for (int i = 1; i < size; i++) {
                if (min > list[i]) { min = list[i]; }
            }
            return min;
        } // ==> O(n)

        virtual ~AList() { delete[] list; } // ==> O(1)
};


// int main() {
//     AList<int> myList(10);
//     myList.addFirst(5);
//     myList.addFirst(2);
//     myList.addFirst(7);

//     cout << "Size: " << myList.getSize() << endl;
//     cout << "Sum: " << myList.getSum() << endl;
//     cout << "Min: " << myList.getMin() << endl;

//     cout << "Prime count: " << myList.countPrime() << endl;

//     cout << "Even elements: ";
//     myList.printEven();
//     cout << endl;

//     myList.removeLast();
//     cout << "Size after removing last: " << myList.getSize() << endl;

//     return 0;
// }