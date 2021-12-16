#include <iostream>
using namespace std;
void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
}
int main() {
	int n, lastnegative = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			lastnegative = arr[i];
	}
	if (lastnegative != 0) {
		for (int i = 0; i < n; i++)
			if (arr[i] < 0)
				arr[i] = lastnegative;
		print(arr, n);
	}
	else print(arr, n);
}