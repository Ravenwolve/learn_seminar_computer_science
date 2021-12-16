#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    int** arr = new int* [m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i++) {
        int s = 0, minx = 0, minj, mini;
        for (int j = 0; j < m; j++)
            if (arr[j][i] < 0) {
                s += arr[j][i];
                if (arr[j][i] < minx)
                    minj = j, mini = i, minx = arr[j][i];
            }
        if (s < 0)
            cout << s << " minE[" << mini << "][" << minj << "]" << endl;
        else cout << -1 << endl;
    }
    for (int i = 0; i < m; i++)
        delete[] arr[i];
    delete[] arr;
}
