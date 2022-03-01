#include <iostream>
#include <cmath>
using namespace std;
template <typename T>
T arr(int N) {
	T* A = new T[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	return *A;
}
int main() {
}