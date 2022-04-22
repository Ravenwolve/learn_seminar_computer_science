#include <iostream>
#include <string>
#include <fstream>
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
    string getSurname() {
        return surname;
    }
    string getName() {
        return name;
    }
    string getLastname() {
        return lastname;
    }
    int getYear() {
        return wasborn;
    }

    int getGroup() {
        return group_number;
    }
    int getO(int n) {
        if (n >= 0 && n < 5)
            return O[n];
        else return 0;
    }
};
bool srav(student x, student y)
{
    if (x.getSurname() != y.getSurname())
        return x.getSurname() < y.getSurname();
    else if (x.getName() != y.getName())
        return x.getName() < y.getName();
    else if (x.getLastname() != y.getLastname())
        return x.getLastname() < y.getLastname();
    else return x.getYear() < y.getYear();
}
void bubblesort(student* A, int n) {
    student temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)
            if (srav(A[j], A[j - 1])) {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
}
int main() {
    student A[10];
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s, n, l;
    int g, y;
    int o[5];
    for (int i = 0; i < 10; i++) {
        fin >> g >> s >> n >> l >> y >> o[0] >> o[1] >> o[2] >> o[3] >> o[4];
        student Temp(g, s, n, l, y, o);
        A[i] = Temp;
    }
    bubblesort(A, 10);
    for (int i = 0; i < 10; i++) {
        fout << A[i].getGroup() << ' ' << A[i].getSurname() << ' ' << A[i].getName() << ' ' << A[i].getLastname() << ' ' << A[i].getYear() << ' ' << A[i].getO(0) << ' ' << A[i].getO(1) << ' ' << A[i].getO(2) << ' ' << A[i].getO(3) << ' ' << A[i].getO(4) << '\n';
    }
}