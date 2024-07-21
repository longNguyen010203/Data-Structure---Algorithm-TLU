#include <iostream>
using namespace std;

class Forum {
    private:
        string ten, hang;
        virtual string rank() const = 0;
    protected:
        void setInfor(string t) {
            ten = t; hang = rank();
        }
    public:
        virtual void print() const {
            cout << ten << " " << hang << " ";
        }
        virtual ~Forum() {}
};

class ForumTinhTe: public Forum {
    private:
        int namGN, namHT;
        string rank() const override {
            if ((namHT - namGN) > 3) return "vang";
            else return "thuong";
        }
    public:
        void setInfor(int n, int m, string t) {
            namGN = n; namHT = m; Forum::setInfor(t);
        }
        void print() const {
            Forum::print(); cout << namGN << " " << namHT << endl;
        }
        ForumTinhTe(int n, int m, string t) { setInfor(n, m, t); }
};

class ForumVnZoom: public Forum {
    private:
        int soBaiDang;
        string rank() const override {
            if (soBaiDang < 200) return "ga con";
            else if (soBaiDang >= 200 && soBaiDang < 400) return "ga choi";
            else return "riu sat";
        }
    public:
        void setInfor(int s, string t) { soBaiDang = s; Forum::setInfor(t); }
        void print() const { Forum::print(); cout << soBaiDang << endl; }
        ForumVnZoom(int s, string t) { setInfor(s,t); }
};



int main() {
    const int s = 10;
    Forum * F[s] = { new ForumTinhTe(2021, 2023, "L"), new ForumVnZoom(23, "K"), 
                     new ForumTinhTe(2021, 2023, "L"), new ForumVnZoom(23, "K"), 
                     new ForumTinhTe(2021, 2023, "L"), new ForumVnZoom(23, "K"), 
                     new ForumTinhTe(2021, 2023, "L"), new ForumVnZoom(23, "K"), 
                     new ForumTinhTe(2021, 2023, "L"), new ForumVnZoom(23, "K") };
    for (int i = 0; i < s; i++) {
        F[i]->print();
    }
    return 0;
}



