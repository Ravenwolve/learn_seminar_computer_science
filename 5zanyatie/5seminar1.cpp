#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    int** arr = new int*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for (int p = 0; p < m; p++)
        for (int k = 0; k < n; k++)
            if (arr[p][k] % 2 == 1)
                cout << p << ' ' << k << '\n';
    for (int i = 0; i < m; i++)
        delete[] arr[i];
    delete[] arr;
}
