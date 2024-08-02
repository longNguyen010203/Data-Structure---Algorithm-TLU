#include <iostream>
using namespace std;



template <class E> 
struct Node{
    E data ; // Lưu giá trị của Node
    Node<E> *next ; // Lưu địa chỉ của Node kế
    
    // Hàm tạo
    Node(E e = E() , Node<E> *l = NULL)
    : data(e), next(l) {}
};

template <class E> 
class Slist{
    protected:
        Node<E> *head ; // Lưu địa chỉ Node đầu tiên
        int size ; // Số lượng Node hiện tại

    public:
        Slist(): head(NULL), size(0) {}
        
        int getSize() const { return size; }
        bool isEmpty() const{ return size == 0; }

        void print() const {
            Node<E> * tmp = head; 
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next ; // Di chuyển sang node kế
            }
        }

        Node<E> *& getLink(int index) {
            if (index < 0 || index >=  size){
                cout << "Lỗi index";
                Node<E> *v = NULL;
                return v->next; // Trỏ đến null
            }
            if (index == 0) { return head; }
            
            Node<E>* tmp = head ;
            for (int i = 0 ; i < index - 1 ; i++)
                tmp = tmp-> next;
            return tmp->next;
        }// ==> Hàm này trả về contrỏ next của node đứng trc node có vị trí index
         // ==> cũng chính là địa chỉ của node có vị trí index

        E getElement(int index) { return getLink(index)->data; }
        E front() const { return head->data; }
        E back() { return getLink(size-1)->data; }

        bool find(const E &value) {
            Node<E>* tmp = head ;
            while (tmp != NULL) {
                if (tmp->data == value) {
                    return true;
                }
                tmp = tmp-> next;
            }
            return false;
        }

        void addFirst(const E& value) {
            Node<E> *v = new Node<E> (value);
            v->next = head; // Trỏ v tới Node đầu tiên thông qua head
            head = v; // trỏ head tới node v
            size++;
        }

        void addLast(const E& value) {
            Node<E> *v = new Node<E> (value);
            if (isEmpty()) { head = v; return; }
            Node<E> *& last = getLink(size-1);
            last->next = v;
            size++;
        }

        void add(int index, const E& value){
            if (index < 0 || index > getSize()) { cout << "Out of Range"; return; }
            if (index == 0) { addFirst(value); return; }
            if (index == getSize()) { addLast(value); return; }
            Node<E> *v = new Node<E> (value);
            Node<E> *& l = getLink(index-1);
            v->next = l->next; // Nối Node mới với node index
            l->next = v;
            size++;
        }

        void removeFirst() {
            if (isEmpty()){ cout << "List is Empty"; return; }
            Node<E> *tmp = head; // Lưu địa chỉ node đầu tiên
            head = head->next; // head trỏ tới node thứ hai trong danh sách
            delete tmp; // Giải phóng node đầu tiên
            size--;
        }

        void removeLast() {
            if (isEmpty()){ cout << "List is Empty"; return; }
            Node<E> *& tmp = getLink(size-1);
            Node<E> *& last = getLink(size-2);
            last->next = NULL;
            delete tmp;
            size--;
        }

        void remove(int index) {
            if (isEmpty()){ cout << "List is Empty"; return; }
            Node<E> *& l = getLink(index);
            Node<E> *tmp = l ; // Lưu địa chỉ Node xóa
            l = l->next; // Nối với Node sau
            delete tmp; // Giải phóng
            size--;
        }

        void removeKey(const E &value) {
            if (isEmpty()){ cout << "List is Empty"; return; }
            if (!find(value)) { cout << "Element not Exists."; return; }
            Node<E> *tmp = head;
            for (int i = 0; i < size; i++) {
                Node<E> *& l = getLink(i);
                if (l->data == value) {
                    Node<E> *tmp = l;
                    l = l->next;
                    delete tmp;
                    size--;
                }
            }
        }

        // Thay đổi giá trị phần tử tại index bằng value
        void replace(int index, const E&value) {
            Node<E> *& l = getLink(index);
            l->data = value;
        }

        // Thay đổi tất cả ptu có giá trị old bằng value
        void replaceKey(const E&old, const E&value) {
            if (!find(old)) { 
                cout << "Element not Exists.";
                return;
            }
            Node<E>* tmp = head;
            while (tmp != NULL) {
                if (tmp->data == old) {
                    tmp->data = value;
                }
                tmp = tmp-> next;
            }
        }

        // Tính tổng các phần tử trong danh sách
        E getSum() {
            if (isEmpty()){
                cout << "Haven't Element"; return E();
            }
            E sum = 0;
            Node<E>* tmp = head;
            while (tmp != NULL) {
                sum += tmp->data;
                tmp = tmp->next;
            }
            return sum;
        }

        // Đếm số lần xuất hiện phần tử value danh sách
        int countValue(const E &value){
            int count = 0;
            Node<E>* tmp = head ;
            while (tmp != NULL) {
                if (tmp->data == value) {
                    count++;
                }
                tmp = tmp-> next;
            }
            return count;
        }

        // Hàm xóa rỗng danh sách
        void clear(){
            Node<E>* tmp = head;
            while (tmp != NULL) {
                Node<E>* next = tmp->next;
                delete tmp;
                tmp = next;
            }
            head = NULL;
            size = 0;
        }
};




int main(){
    Slist<int> s; // Rỗng
    s.addFirst(4) ; // 4 : size = 1 
    s.print();
    cout <<endl;
    s.addFirst(1) ; // 1 4 size = 2 
    s.print();
    cout <<endl;
    s.addFirst(2) ; // 2 1 4 size = 3 ;
    s.print();
    cout << endl;
    cout << s.getElement(1)<<endl; // 1
    cout << s.getElement(0)<<endl; // 2
    cout << s.getElement(2)<<endl; // 4
    s.replace(1, 10);
    s.replace(0, 100);
    s.print();
    cout << endl;
    cout << s.getSum() << endl;
    cout << s.find(18) << endl;
    s.addFirst(1111);
    s.replaceKey(4, 2008);
    s.print();
    cout << endl;
    cout << s.front() << endl;
    cout << s.back() << endl;
    s.addLast(123);
    s.print();
    s.removeLast();
    cout << endl;
    s.print();
    cout << endl;
    s.add(2, 2003);
    s.print();
    cout << endl << s.getSize() << endl;
    s.removeFirst();
    s.print();
    cout << endl;
    s.remove(2);
    s.print();
    cout << endl;
    s.add(3, 345);
    s.print();
    cout << endl;
    s.remove(3);
    s.print();

    cout << endl;
    s.removeKey(2003);
    s.print();
    return 0 ;
}