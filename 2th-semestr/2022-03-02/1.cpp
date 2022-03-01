#include <iostream>
using namespace std;
void println(int N, bool b) {
    for (int i = 0; i < N; i++)
        cout << b;
    cout << '\n';
}
void rec(int N, int k = 1) {
    bool symb;
    if (k % 2 == 0)
        symb = 1;
    else symb = 0;
    if (k <= N) {
        println(k, symb);
        rec(N, k + 1);
        if (k < N)
            println(k, symb);
    }
}
int main() {
    rec(4);
}