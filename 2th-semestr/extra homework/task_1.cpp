#include <iostream>
using namespace std;
void rec(int N, int k = 0) {
    if ((N + 1) / 2 - k > 0) {
        int len_str = (N + 1) / 2; //вопрос: стоит ли заводить для значения этой операции отдельную переменную, чтобы не производить расчеты постоянно? эффективнее ли это?
        for (int i = 1; i <= len_str; i++) {
            if (i == len_str - k || i == len_str)
                cout << '*';
            else cout << ' ';
        }
        cout << endl;
        rec(N, k + 1);
        if (len_str - k != 1) {
            for (int i = 1; i <= len_str; i++) {
                if (i == len_str - k || i == len_str)
                    cout << '*';
                else cout << ' ';
            }
            cout << endl;
        }
    }
}
int main() {
    int N;
    cin >> N;
    rec(N);
}