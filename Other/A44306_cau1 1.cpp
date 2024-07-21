#include <iostream>
using namespace std;

class Array {
    private:
        int size;
        double a[100];
        bool check(int n) const {
            if (n < 0 || n > size) return false;
            else return true;
        }
    public:
        Array(int s, double m) {
            if (s < 0 || s > 100) {
                throw "Loi\n";
            } size = s;
            a[0] = m;
        }
        int getSize() const { return size; }
        double get(int i) const {
            if (check(i)) return a[i];
            else {
                cout << "Loi chi muc\n";
                return -1;
            }
        }
        void set(int i, double m) {
            if (check(i)) a[i] = m;
            else cout << "Loi chi muc\n";
        }
        double getMin() const {
            double min = a[0];
            for (int i = 0; i < size; i++) {
                if (min > a[i]) min = a[i];
            } return min;
        }
        double getMean() const {
            double sum = 0;
            for (int i = 0; i < size; i++) {
                sum += a[i];
            } return sum / size;
        }
        void print() const {
            cout << size << endl;
            for (int i = 0; i < size; i++) {
                cout << a[i] << " ";
            }
        }
};

int main() {
    Array a(3, 2);
    a.set(0, 12);
    a.set(1, 13);
    a.set(2, 14);
    cout << a.get(1) << " " << a.getMin() <<  " " << a.getMean() << endl;
    a.print();
    return 0;
}