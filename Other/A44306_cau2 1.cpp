#include <iostream>
using namespace std;

class ThoiGian {
    private:
        int gio, phut, giay;
        void chuanHoa() {
            int p = phut, g = giay;
            p /= 60;
            g /= 60;
            gio += p; 
            phut += g; 
            phut %= 60;
            giay %= 60;
        }
        static int count;
    public:
        ThoiGian(): gio(0), phut(0), giay(0) { chuanHoa() ;count++; }
        
        ThoiGian(int g, int p, int s): gio(g), phut(p), giay(s) {
            chuanHoa(); count++;
        }
        void print() const {
            cout << gio << ":" << phut << ":" << giay << endl;
        }
        ThoiGian operator+(const ThoiGian& t) {
            return ThoiGian(gio+t.gio, phut+t.phut, giay+t.giay);
        }
        // static int getCount() { return count; } bỏ
        
};
int ThoiGian::count = 0;

int main() {
    ThoiGian t(12, 162, 64), m(12, 64, 62);
    ThoiGian w = t + m; w.print();
    // cout << ThoiGian::getCount() << endl; bỏ
    t.print();
    return 0;
}
