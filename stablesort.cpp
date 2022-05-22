#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
class student {
    int group_number;
    string surname, name, lastname;
    int wasborn;
    int O[5];
public:
    student() : group_number(000), surname("_"), name("_"), lastname("_"), wasborn(0) {
        for (int i = 0; i < 5; i++)
            O[i] = 0;
    }
    student(int g, string s, string n, string l, int y, int* o) : group_number(g), surname(s), name(n), lastname(l), wasborn(y) {
        for (int i = 0; i < 5; i++)
            O[i] = o[i];
    }
    string getSurname() { return surname; }
    string getName() { return name; }
    string getLastname() { return lastname; }
    int getYear() { return wasborn; }
    int getGroup() { return group_number; }
    int getO(int n) {
        if (n >= 0 && n < 5)
            return O[n];
        else return 0;
    }
    friend istream& operator>>(istream& in, student& S) { return in >> S.group_number >> S.surname >> S.name >> S.lastname >> S.wasborn >> S.O[0] >> S.O[1] >> S.O[2] >> S.O[3] >> S.O[4]; }
};
int main() {
    ifstream fin("input.txt");
    vector<student> Students;
    for (student a; fin >> a; Students.push_back(a));
    stable_sort(Students.begin(), Students.end(), [](student a, student b) { 
        return a.getO(0) + a.getO(1) + a.getO(2) + a.getO(3) + a.getO(4) > b.getO(0) + b.getO(1) + b.getO(2) + b.getO(3) + b.getO(4);
        });
    for (student st : Students)
        cout << st.getGroup() << ' ' << st.getSurname() << ' ' << st.getName() << ' ' << st.getLastname() << ' ' << st.getYear() << ' ' << st.getO(0) + st.getO(1) + st.getO(2) + st.getO(3) + st.getO(4) << endl;
}
