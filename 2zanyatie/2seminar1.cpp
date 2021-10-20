#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Эта программа исключает все положительные числа от n до m, которые делятся на 5" << endl << "Введите число n: ";
    cin >> n;
    cout << "Введите число m: ";
    cin >> m;
    if (n <= m && n > 0)
    {
        cout << "Остались числа ";
        for (n; n <= m; n++)
        {
            if (n % 5 == 0)
            {
                continue;
            }
            cout << n << ' ';
        }
    }
    else
        cout << "Такого продукта не существует" << endl;
}