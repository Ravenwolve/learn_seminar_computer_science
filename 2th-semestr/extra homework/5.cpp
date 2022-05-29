#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class date {
public:
    short day, month;
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
class holiday : public date {
    string name;
public:
    string getname() { return name; }
    holiday() : name("unknown") {}
    holiday(string n, short d, short m) {
        if (m > 0 && m <= 12 && d > 0 && d <= 31) {
            if (m == 2 && d <= 28) {
                name = n;
                month = m;
                day = d;
            }
            else if (m == 4 || m == 6 || m == 9 || m == 11 && d <= 30) {
                name = n;
                month = m;
                day = d;
            }
            else {
                name = n;
                month = m;
                day = d;
            }
        }
    }
    friend istream& operator>>(istream& in, holiday& h) { return in >> h.name >> h.day >> h.month; }
};
ostream& operator<<(ostream& out, holiday h) { return out << h.getname() << ' ' << h.getday() << ' ' << h.getmonth(); }
int main() {
    holiday h1;
    vector<holiday> HVector;
    list<holiday> HList;
    int N;
    cin >> N;
    for (int i = 0; i < 10; i++, HList.push_back(h1))
        cin >> h1;
    cin >> N; //Удаляет месяц, номер которого равен данному
    remove_if(HList.begin(), HList.end(), [N](holiday a) { return a.getmonth() == N; });
    while (!HList.empty()) {
        HVector.push_back(HList.front());
        HList.pop_front();
    }
    cin >> N; //Считает те праздники, дни которых кратны данному числу
    count_if(HVector.begin(), HVector.end(), [N](holiday a) { return a.getday() % N == 0; });
}
