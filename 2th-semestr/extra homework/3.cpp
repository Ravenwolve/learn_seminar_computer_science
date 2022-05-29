#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class student {
    string surname, name;
    int o[3];
    bool stringcondition(string newname) { //Метод-проверка на то, что все символы строки - буквы.
        if (newname[0] > 64 && newname[0] < 91) {
            for (int i = 1; i < newname.size(); i++)
                if (newname[i] < 97 && newname[i] > 122)
                    return false;
            return true;
        }
        return false;
    }
public:
    student() {
        for (int i = 0; i < 3; i++)
            o[i] = 0;
    }
    student(string s, string n, int o1, int o2, int o3) {
        if (o1 > 0 && o2 > 0 && o3 > 0 && o1 <= 100 && o2 <= 100 && o3 <= 100 && stringcondition(surname) && stringcondition(name)) {
            surname = s;
            name = n;
            o[0] = o1;
            o[1] = o2;
            o[2] = o3;
        }
    }
    string getsurname() { return surname; }
    string getname() { return name; }
    int geto(int N) {
        if (N >= 0 && N < 3)
            return o[N];
    }
    friend istream& operator>>(istream& in, student& stud) { return in >> stud.surname >> stud.name >> stud.o[0] >> stud.o[1] >> stud.o[2]; }
};
ostream& operator<<(ostream& out, student stud) { return out << stud.getsurname() << ' ' << stud.getname() << ' ' << stud.geto(0) << ' ' << stud.geto(1) << ' ' << stud.geto(2); }
bool pred(student a, student b) {
    int count_1 = 0, count_2 = 0;
    for (int i = 0; i < 3; i++) {
        if (a.geto(i) > 64)
            count_1++;
        if (b.geto(i) > 64)
            count_2++;
    }
    if (count_1 == count_2)
        return a.getsurname() > b.getsurname();
    else return count_1 > count_2;
}
int main() {
    ifstream fin("input.txt");
    vector<student> V;
    for (student s; fin >> s; V.push_back(s));
    stable_sort(V.begin(), V.end(), pred);
    for (student S : V)
        cout << S << endl;
}
