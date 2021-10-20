#include <iostream>

using namespace std;

int main()
{
    int n, secondmina, mina, at, atm;
    secondmina = 0;
    cout << "Введите количество чисел: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > 0 && i == 0)
            at = a;
        if (a < at)
        {
            secondmina = at;
            at = a;
        }
    }
    cout << secondmina << endl;
}
