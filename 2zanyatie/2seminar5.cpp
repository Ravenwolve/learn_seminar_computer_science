#include <iostream>

using namespace std;

int main()
{
    int c, d, h;
    cout << "Введите диапазон значений: ";
    cin >> c >> d;
    cout << "Введите шаг: ";
    cin >> h;
    for (int x, int a, int b, int y; c < d; c += h)
    {
        x++;
        cin >> a >> b;
        y = func(a, b, x);
        cout << y;
    }
}
int func(int a, int b, int x)
{
    return a * x * x * x + b / (x - 1);
}
// Я пытался...