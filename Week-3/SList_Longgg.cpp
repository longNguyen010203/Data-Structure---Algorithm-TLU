#include <iostream>
using namespace std;


template <class E>
struct Node {
    E element; // Lưu giá trị của Node
    Node<E> *next; // Lưu địa chỉ của Node kế
    Node(E e = E(), Node<E> *n = NULL)
    : element(e), next(n) {}
};


template <class E>
class SList {
    protected:
        Node<E> *head; // Lưu địa chỉ của Node đầu tiên
        int size; // Lưu số lượng Node hiện tại
    public:
        // Hàm tạo
        SList(): head(NULL), size(0) {};
        // Kiểm tra rỗng
        bool isEmpty() const { return head == NULL || size == 0; }

        // Lấy ra kích thước của list
        int getSize() const { return size; }

        Node<E> *& getlink(int index) {
            if (index <= 0 || index > size){
                cout << "Lỗi index";
                Node<E> *v = new Node<E>();
                return  v->next; // Trỏ đến null
            }
            if (index == 0)
                return head;
            
            Node<E>* tmp = head ;
            for ( int i = 0 ; i < index - 1 ; i++)
                tmp = tmp-> next;
            return tmp->next;
        }

        void print() const {
            if (isEmpty()) { 
                cout << "List is Empty!"; 
                return;
            }
            Node<E>* tmp = head;
            while (tmp != NULL) {
                cout << tmp->element << " ";

                // Di chuyển sang Node kế
                tmp = tmp->next;
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
            Node<E>* tmp = new Node<E>(data);
            if (isEmpty()) { head = tmp; return; } 
            tmp->next = head; 
            head = tmp; 
            size++;
        }

        // Thêm phần tử vào cuối danh sách
        void addLast(const E &data) {
            Node<E>* newNode = new Node<E>(data);
            if (isEmpty()) { head = newNode; return; } 
            Node<E>* tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
            size++;
        }

        // Thêm một Node vào vị trí i
        void add (int i, const E &data) {
            if (i <= 0 || i > getSize()+1) { cout << "Out of range"; return; }
            if (i == 1) { addFirst(data); size++;}
            else if (i == getSize()+1) { addLast(data); size++; } 
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
            if (isEmpty()) { cout << "List is Empty!"; return; }
            if (getSize() == 1) {head = NULL; size--; return;}
            Node<E> *first = head;
            head = head->next;
            delete first;
            size--;
        }

        // Xóa phần tử cuối
        void removeLast() {
            if (isEmpty()) { cout << "List is Empty!"; return; }
            if (getSize() == 1) {head = NULL; size--; return;}
            Node<E>* current = head;
            Node<E>* last = head->next;
            for (int i = 1; i < size-1; i++) {
                current = current->next;
                last = last->next;
            }
            current->next = NULL;
            delete last;
            size--;
        }

        // Xóa một Node tại vị trí i
        void remove(int i) {
            if (isEmpty()) { cout << "List is Empty!"; return; }
            if (i <= 0 || i > getSize()) { cout << "Out of range"; return; }
            if (i == 1) { removeFirst(); size--; }
            else if (i == getSize()) { removeLast(); size--; }
            else {
                Node<E>* begin = head;
                Node<E>* back = head->next;
                for (int j = 1; j < i-1; j++) {
                    begin = begin->next;
                    back = back->next;
                }
                begin->next = back->next;
                // back->next = NULL;
                delete back;
                size--;
            }
        }

        // lấy ra node tại vị trí i
        Node<E> *& getLink(int index) {
            if (index <= 0 || index > getSize()) { 
                cout << "Out of range"; return Node<E>(); 
            }
            if (index == 1) { return head; }
            Node<E> *tmp = head;
            for (int i = 0; i < index-1; i++) {
                tmp = tmp->next;
            }
            return tmp->next;
        }

        // Lấy ra dữ liệu tại vị trí i
        E getElement(int index) const {
            if (index <= 0 || index > getSize()) { 
                cout << "Out of range"; return E(); 
            }
            if (index == 1) { return head->element; }
            Node<E> *tmp = head;
            for (int i = 0; i < index-1; i++) {
                tmp = tmp->next;
            }
            return tmp->element;
        }

        E front() const {
            return head->element;
        }

        E back() {
            Node<E>* last = head->next;
            for (int i = 1; i < size-1; i++) {
                last = last->next;
            }
            return last->element;
        }

};


int main() {

    SList<int> list;
    list.addFirst(40);
    list.addFirst(30);
    list.addFirst(20);
    list.addLast(50);
    list.add(3, 35);
    list.print();
    cout << endl;
    list.removeFirst();
    list.removeLast();
    list.remove(2);
    list.print();
    cout << endl;
    cout << list.getElement(2) << endl;;
    cout << list.front() << " " << list.back() << endl;
    return 0;
}

