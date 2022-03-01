#include <iostream>
using namespace std;
double proizv(double *array, int N) {
    if (N > 1)
        return array[N - 1] * proizv(array, N - 1);
    else return array[N - 1];
}
int main() {
    int N;
    cin >> N;
    double* A = new double[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cout << proizv(A, N);
}