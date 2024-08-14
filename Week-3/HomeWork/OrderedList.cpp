#include <iostream>
using namespace std;


template <typename E>
class OrderedList {
    protected:
        int maxSize;
        int size;
        E *list;

    public:
        OrderedList(int maxSize = 100) {
            this->size = 0;
            this->maxSize = maxSize;
            list = new E[maxSize];
        }

        int getSize() const { return size; }
        bool isEmpty() const { return size == 0; }
        bool isFull() const { return size == maxSize; }

        bool find(const E &e) const {
            for (int i = 0; i < size; i++) {
                if (e == list[i]) {
                    return true;
                }
            }
            return false;
        }

        int findPosition(const E &e) {
            int pos = 0;
            int length = getSize();

            while (pos < length) {
                int index = pos + (length - pos) / 2;
                if (list[index] < e) {
                    pos = index + 1;
                } else {
                    length = index;
                }
            }
            return pos;
        }

        void add(const E &e) {
            if (isFull()) { cout << "List is Full"; return; }
            if (isEmpty()) { list[0] = e; size++; return; }
            int pos = findPosition(e);
            for (int i = size; i >= pos; i--) {
                list[i] = list[i - 1];
            }
            list[pos] = e;
            size++;
        } 

        void replace(int i, const E &e) {
            if (i < 0 || i >= size) { cout << "Out of range"; return; }
            for (int j = i; j < size; j++) {
                list[j] = list[j+1];
            }
            size--;
            add(e);
        }


        void print() const {
            for (int i = 0; i < size; i++) {
                cout << list[i] << ' ';
            }
        }



};


int main() {

    OrderedList<int> o;
    o.add(1);
    o.add(5);
    o.add(9);
    o.print();
    cout << endl << o.getSize() << endl;
    o.replace(1, 0);
    o.print();
    return 0;
}
