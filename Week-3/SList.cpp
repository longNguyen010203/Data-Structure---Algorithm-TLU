#include <iostream>
using namespace std;


template <class E>
struct Node {
    E element;
    Node<E> *next;
    Node(E e = E(), Node<E> *n = NULL)
    : element(e), next(n) {}
};


template <class E>
class SList {
    protected:
        Node<E> *head;
        int size;
    public:
        
        SList(): head(NULL), size(0) {}; // Hàm tạo
        bool isEmpty() const { return head == NULL; } // Kiểm tra rỗng
        int getSize() const { return size; } // Lấy ra kích thước của list

        void print() const {
            if (isEmpty()) { throw "List is Empty!"; }
            else {
                Node<E>* current = head;
                while (current != NULL) {
                    cout << current->element << " ";
                    current = current->next;
                }
            }
        }

        // Cấp phát động một node mới
        Node<E>* makeNode(const E &data) { 
            Node<E>* tmp = new Node<E>();
            tmp->element = data;
            tmp->next = NULL;
            return tmp;
        }

        // Thêm phần tử vào đầu danh sách 
        void addFirst(const E &data) {
            Node<E>* tmp = makeNode(data);
            if (isEmpty()) { head = tmp; } 
            else { tmp->next = head; head = tmp; }
            size++;
        }

        // Thêm phần tử vào cuối danh sách
        void addLast(const E &data) {
            Node<E>* tmp = makeNode(data);
            if (isEmpty()) { head = tmp; } 
            else { 
                Node<E>* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = tmp;
            }
            size++;
        }

        // Thêm một phần tử vào vị trí i
        void add (int i, const E &data) {
            if (i <= 0 || i > getSize()+1) { throw "Out of range"; }
            if (i == 1) { addFirst(data); size++; return;}
            else if (i == getSize()+1) { addLast(data); size++; return; } 
            else {
                Node<E>* current = head;
                Node<E>* tmp = makeNode(data);
                for (int j = 1; j < i-1; j++) {
                    current = current->next;
                }
                tmp->next = current->next;
                current->next = tmp;
                size++;
            }
        }

        // Xóa phần tử đầu
        void removeFirst() {
            if (isEmpty()) { throw "List is Empty!"; }
            head = head->next;
            size--;
        }

        // Xóa phần tử cuối
        
};


int main() {

    SList<int> list;
    list.addFirst(20);
    list.addFirst(30);
    list.addFirst(40);
    list.addLast(50);
    list.add(2, 100);
    list.removeFirst();
    list.addFirst(1);
    list.print();
    cout << endl;
    cout << list.getSize();

    return 0;
}