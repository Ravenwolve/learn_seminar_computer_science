#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int k, n;
    n = 1;
    cout << "Введите крайнее значение: ";
    cin >> k;
    if (k > 0)
    {
        for (n; n <= k; n++)
        {
            cout << n << endl;
        }
    }
    else if (k < 0)
    {
        for (n; n >= k; n--)
        {
            cout << n << endl;
        }
    }
    else
        cout << n << endl << n - 1 << endl;
}