#include <iostream>
using namespace std;
class date {
    short day, month;
public:
    date() : day(0), month(0) {}
    date(int d, int m) {
        if (m > 0 && m <= 12 && d > 0 && d <= 31) {
            if (m == 2 && d <= 28) {
                month = m;
                day = d;
            }
            else if (m == 4 || m == 6 || m == 9 || m == 11 && d <= 30) {
                month = m;
                day = d;
            }
            else {
                month = m;
                day = d;
            }
        }
    }
    short getday() { return day; }
    short getmonth() { return month; }
    friend istream& operator>>(istream& in, date& d) { return in >> d.day >> d.month; }

};
ostream& operator<<(ostream& out, date d) { return out << d.getday() << '.' << d.getmonth(); }
class holiday {
    string name;
    date date_;
public:
    string getname() { return name; }
    date getdate() { return date_; }
    holiday() : name("unknown") {}
    holiday(string n, short d, short m) {
        date_ = { d, m };
        name = n;
    }
    friend istream& operator>>(istream& in, holiday& h) { return in >> h.name >> h.date_; }
};
ostream& operator<<(ostream& out, holiday h) { return out << h.getname() << ' ' << h.getdate(); }
int main() {
    holiday h1;
    cout << h1;
    h1 = { "New Year", 31, 12 };
    cout << endl;
    cout << h1;
}
