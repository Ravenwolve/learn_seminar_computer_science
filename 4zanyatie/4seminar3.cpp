#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите количество целых чисел: ";
    cin >> N;
    if (N > 0)
    {
        int* A = new int[N];
        for (int i = 0; i < N; i++)
        {
            cout << "Введите " << i << "-е целое число: ";
            cin >> A[i];
        }
        if (N % 2 == 0)
        {
            int flag = A[N / 2];
            A[N / 2] = A[N / 2 - 1];
            A[N / 2 - 1] = flag;
        }
        else A[(N - 1) / 2] *= 2;
        for (int i = 0; i < N; i++, cout << '\t')
        {
            cout << A[i];
        }    
    }
    else cout << "Вы ввели некорректное значение N.";
}
