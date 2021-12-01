#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите количество чисел Фибоначчи: ";
    cin >> N;
    if (N > 0)
    {
        unsigned long int* fibonacci = new unsigned long int[N];
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        for (int i = 2; i < N; i++)
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
        for (int k = N - 1; k >= 0; k--, cout << '\t')
        {
            cout << fibonacci[k];
        }
    }
    else cout << "Вы ввели некорректное значение!!!" << endl;
}