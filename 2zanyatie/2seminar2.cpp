#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, o;
    o = 0;
    cout << "Введите количество чисел: ";
    cin >> m;
    cout << "Введите сами числа: " << endl;
    for (int i = 0; i < m; ++i)
    {
        int a;
        cin >> a;
        if (a < 0)
            o += a;
    }
    cout << "Сумма отрицательных чисел равна " << o << endl;
}