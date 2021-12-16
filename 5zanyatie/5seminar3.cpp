#include <iostream>
using namespace std;
int main() {
    int x, A = 1;
    while (cin >> x)
        if (x % 13 != 0 || x == 0) {
            if (x != 0 && x % 10 == 0)
                A *= x;
        }
        else break;
    cout << A;
}