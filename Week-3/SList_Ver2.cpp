#include<iostream>

using namespace std ;

template <class E> 
struct Node{
    E data ; // Lưu giá trị của Node
    Node<E> *next ; // Lưu địa chỉ của Node kế

    Node(E e = E() , Node<E> *l = 0):
    data(e),next(l){}
};

template <class E> 
class Slist{
    protected:
        Node<E> *head ; // Lưu địa chỉ Node đầu tiên
        int size ; // Số lượng Node hiện tại

    public:
        Slist():head(NULL),size(0){}
        
        int getSize() const{
            return size ;
        }

        bool isEmpty() const{
            return size == 0;
        }

        // Thử tìm cách viết lại print theo vòng for
        void print() const {
            Node<E> * tmp = head; 

            while(tmp != 0) {
                cout << tmp -> data <<" ";
                tmp = tmp->next ; // Di chuyển sang node kế
            }
        }

        E front() const {
            return head->data;
        }

        E back() {
            Node<E>* last = head->next;
            for (int i = 1; i < size-1; i++) {
                last = last->next;
            }
            return last->data;
        }

        void addFirst(const E& value) {
            Node<E> *v = new Node<E> (value); // Khởi tạo Node giá trị value
            v->next = head ; // Trỏ v tới Node đầu tiên
            head = v ;
            size++;
        }

        void addLast(const E& value) {
            Node<E> *v = new Node<E> (value);
            if (isEmpty()) { head = v; return; }
            Node<E> *last = getlink(size-1);
            last->next = v;
            size++;
        }

        void removeFirst() {
            if (isEmpty() == true){
                cout << "Danh sách không phần tử";
                return ;
            }

            Node<E> *v = head ; // Lưu địa chỉ node đầu tiên
            head = head -> next ; 
            delete v ;
            size--;
        }

        void removeLast() {
            if (isEmpty() == true){
                cout << "Danh sách không phần tử";
                return ;
            }

            Node<E> *tmp = getlink(size-1);
            Node<E> *last = getlink(size-2);
            last->next = NULL;
            delete tmp;
            size--;
        }

        Node<E> *& getlink(int index) {
            if (index < 0 || index >=  size){
                cout << "Lỗi index";
                Node<E> *v = new Node<E>();
                return  v->next; // Trỏ đến null
            }
            if (index == 0)
                return head;
            
            Node<E>* tmp = head ;
            for (int i = 0 ; i < index - 1 ; i++)
                tmp = tmp-> next;
            return tmp->next;
        }

        E getElement(int index) {
            return getlink(index)->data;
        }

        void add(int index, const E& value){
            Node<E> *v = new Node<E> (value); // Khởi tạo Node 
            Node<E> *& l = getlink(index) ; // lấy địa chỉ của Node thứ index
            v -> next = l ; // Nối Node mới với node index
            l = v ;
            size++;
        }

        void add (int i, const E &data) {
            if (i < 0 || i > getSize()) { cout << "Out of range"; return; }
            if (i == 1) { addFirst(data); size++;}
            else if (i == getSize()) { addLast(data); size++; } 
            else {
                Node<E> *v = new Node<E> (data);
                Node<E>* e2 = getlink(i);
                v->next = e2->next;
                tmp->next = v;
                size++;
            }
        }

        void remove(int index) {
            Node<E> *&l = getlink(index);
            Node<E> *tmp = l ; // Lưu địa chỉ Node xóa
            l = l->next; // Nối với Node sau
            delete tmp; // Giải phóng
            size--;
        }

        // Thay đổi giá trị phần tử tại index bằng value
        void replace(int index, const E&value) {
            Node<E> *& l = getlink(index);
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

        // Kiểm tra phần tử value có tồn tại trong danh sách
        bool find(const E &value){
            Node<E>* tmp = head ;
            while (tmp != NULL) {
                if (tmp->data == value) {
                    return true;
                }
                tmp = tmp-> next;
            }
            return false;
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
    s.addFirst(1025);
    s.replaceKey(4, 2003);
    s.print();
    cout << endl;
    cout << s.front() << endl;
    cout << s.back() << endl;

    s.addLast(123);
    s.print();
    s.removeLast();
    cout << endl;
    s.print();
    return 0 ;
}