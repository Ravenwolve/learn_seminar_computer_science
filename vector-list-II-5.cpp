#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;
class merchandise {
    string name;
    int weight;
public:
    merchandise() : weight(0) {}
    merchandise(string n, int w) {
        if (w > 0) {
            weight = w;
            name = n;
        }
    }
    string getname() { return name; }
    int getweight() { return weight; }
    friend istream& operator>>(istream& in, merchandise &m) { return in >> m.name >> m.weight; }
    friend ostream& operator<<(ostream& out, merchandise m) { return out << m.getname() << ' ' << m.getweight(); }
    bool operator>(int w) { return weight > w; }
    merchandise operator=(merchandise A) { return A; }
    merchandise operator/=(int n) { return { name, weight /= 2 }; }
};
class storage_list {
    list<merchandise> wares;
public:
    void push_back(merchandise m) { wares.push_back(m); }
    void divide(int w) {
        if (!wares.empty() && w > 0)
            for (list<merchandise>::iterator iter = wares.begin(); iter != wares.end(); iter++)
                if (*iter > w) {
                    *iter /= 2;
                    wares.insert(iter, *iter);
                }
    }
    void show() {
        if (!wares.empty())
            for (list<merchandise>::iterator iter = wares.begin(); iter != wares.end(); iter++)
                cout << *iter << '\n';
    }
};
class storage_vector {
    vector<merchandise> wares;
public:
    void push_back(merchandise m) { wares.push_back(m); }
    merchandise showmidst() { return wares[wares.size() / 2]; }
    void divide(int w) {
        if (!wares.empty() && w > 0)
            for (int i = 0; i < wares.size(); i++)
                if (wares[i] > w) {
                    wares[i] /= 2;
                    wares.push_back(wares[i]);
                }
    }
    void show() {
        if (!wares.empty())
            for (vector<merchandise>::iterator iter = wares.begin(); iter != wares.end(); iter++)
                cout << *iter << endl;
    }
};
int main() {
    ifstream fin("input.txt");
    int N;
    merchandise Merch;
    storage_list List;
    storage_vector Vector;
    fin >> N;
    while (fin >> Merch) {
        List.push_back(Merch);
        Vector.push_back(Merch);
    }
    //------------- Задача А: Разбить всё что тяжелее N кг на две идущие подряд записи по N/2 кг. Добавить новый товар в конец списка -------------
    cout << "A: " << endl << "1) Showing list" << endl;
    List.show();
    cout << endl << "2) Divide method call" << endl;
    List.divide(N);
    List.show();
    cout << endl << "3) Push back method call" << endl;
    List.push_back(Merch);
    List.show();
    //- Задача Б: Разбить всё что тяжелее N кг на две записи по N/2 кг, первую оставить на прежнем месте, а вторую приписать в конец списка. Показать товар, расположенный в середине списка -
    cout << "B: " << endl << "1) Showing vector" << endl;
    Vector.show();
    cout << endl << "2) Divide method call" << endl;
    Vector.divide(N);
    Vector.show();
    cout << endl << "3) Showing middle element method call" << endl;
    cout << Vector.showmidst();
}
/* INPUT
5
Lightsaber 7
Beherit 4
Konohagakure_Bandage 5
Iron_throne 3
Portal_gun 3
PDA 4
Sheldon's_Place 4
Hidden_blade 5
Chocolate 3
Videocard 8
Gameboy 9
Calculator 2
Fax 4
Pen 5
Apple 5
Juice 8
Skill 9
Apple 5
Visor 7
Shotgun 7
*/
