#include <iostream>
using namespace std;
bool change(int a, int b, int c) {
    int a0 = a, b0 = b, c0 = c;
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    if (a == a0 && b == b0 && c == c0)
        return false;
    else return true;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (change(a, b, c))
        cout << "true";
    else cout << "false";
}