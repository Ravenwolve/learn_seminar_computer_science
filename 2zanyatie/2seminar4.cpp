#include <iostream>

using namespace std;

int main()
{
    int n, k;
    k = 0;
    n = 1;
    for (int i = 0; n != 0; i++)
    {
        cin >> n;
        if (n != 0 && n % 2 != 0)
        {
            k++;
        }
    }
    cout << k;
}
