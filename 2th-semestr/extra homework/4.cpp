#include <iostream>
#include <stack>
#include <queue>
using namespace std;
bool primenumber(int N) {
    if (N > 1) {
        for (int i = 2; i * i < N; i++)
            if (N % i == 0)
                return false;
        return true;
    }
    return false;
}
bool squareroot(int N) {
    for (int i = 2; i < N; i++)
        if (i * i == N)
            return true;
    return false;
}
int main() {
    stack<int> S;
    queue<int> Q;
    int N;
    cout << "Enter N: ";
    cin >> N;
    for (int i = 0, k; i < N; i++) {
        cin >> k;
        if (squareroot(k))
            S.push(k);
        else if (primenumber(k))
            Q.push(k);
    }
    while (!Q.empty()) {
        cout << Q.front() << ' ';
        Q.pop();
    }
    while (!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }
}
