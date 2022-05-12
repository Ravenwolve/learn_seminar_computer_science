#include <iostream>
using namespace std;
void pushdown(int*& A, int first_index, int last_index, bool descending) {
	int r = first_index;
	while (r <= last_index / 2) {
		if (last_index == 2 * r) {
			if (A[r] > A[2 * r])
				swap(A[r], A[2 * r]);
			r = last_index;
		}
		else if (A[r] > A[2 * r] && A[2 * r] <= A[2 * r + 1]) {
			swap(A[r], A[2 * r]);
			r = 2 * r;
		}
		else if (A[r] > A[2 * r + 1] && A[2 * r + 1] < A[2 * r]) {
			swap(A[r], A[2 * r + 1]);
			r = 2 * r + 1;
		}
		else r = last_index;
	}
}
void heapsort(int*& A, int N, bool descending = 0) {
	for (int i = N / 2; i >= 1; i--)
		pushdown(A, i, N, descending);
	for (int i = N; i >= 2; i--) {
		swap(A[1], A[i]);
		pushdown(A, 1, i - 1, descending);
	}
}
void quicksort(int*& A, int first_index, int last_index, bool descending = 0) {
	int l = first_index, r = last_index;
	int pivot = A[(l + r) / 2];
	if (!descending) {
		do {
			while (A[l] < pivot)
				l++;
			while (A[r] > pivot)
				r--;
			if (l <= r) {
				swap(A[l], A[r]);
				l++;
				r--;
			}
		} while (l < r);
	}
	else {
		do {
			while (A[l] > pivot)
				l++;
			while (A[r] < pivot)
				r--;
			if (l <= r) {
				swap(A[l], A[r]);
				l++;
				r--;
			}
		} while (l < r);
	}
	if (first_index < r)
		quicksort(A, first_index, r);
	if (l < last_index)
		quicksort(A, l, last_index);
}
void diagonal_sort(int** &A, int A_size) {
	int** D = new int* [(A_size - 2) * 2]; //будущий одномерный массив одномерных массивов диагоналей (кривой двумерный массив)
	for (int k = 1; k < A_size - 1; k++) { //создание массивов диагоналей
			D[k - 1] = new int[A_size - k]; //D[j] ?
			D[k + A_size - 3] = new int[A_size - k]; //D[i - 1 + A_size - 2] = D[i + A_size - 2] - смещение для отличия индексов
	}
	for (int i = 0; i < A_size; i++)
		for (int j = 0; j < A_size; j++) {
			if (i < j && (i != 0 || j != A_size - 1))
				D[j - i - 1][i] = A[i][j];
			else if (i > j && (i != A_size - 1 || j != 0))
				D[i - j - 1 + A_size - 2][j] = A[i][j];
		}
	for (int i = 0, j = A_size - 2; i < (A_size - 2) * 2; i++, j--) { //специфическая пробежка по кривому массиву с вызовом сортировки для каждого подмассива (каждой диагонали)
		if (i < A_size - 2) {
			//quicksort(D[i], 0, j);
			heapsort(D[i], j + 1);
		}
		else {
			//quicksort(D[i], 0, j, true);
			heapsort(D[i], j + 1, true);
		}
	}
	for (int i = 0; i < A_size; i++)
		for (int j = 0; j < A_size; j++) {
			if (i < j && (i != 0 || j != A_size - 1))
				A[i][j] = D[j - i - 1][i];
			else if (i > j && (i != A_size - 1 || j != 0))
				A[i][j] = D[i - j - 1 + A_size - 2][j];
		}
	//for (int i = 0, k = A_size - 2; i < (A_size - 2) * 2; i++, k--) { //проверка диагоналей
	//	if (i == A_size - 2)
	//		k = A_size - 2;
	//	for (int j = 0; j <= k; j++)
	//		cout << D[i][j] << '\t';
	//	cout << endl;
	//}
}
void print_array(int** A, int A_size) {
	for (int i = 0; i < A_size; i++, cout << endl)
		for (int j = 0; j < A_size; j++, cout << '\t')
			cout << A[i][j];
}
int main() {
	int N;
	cin >> N;
	int** Array = new int*[N];
	for (int i = 0, k = 36; i < N; i++) {
		Array[i] = new int[N];
		for (int j = 0; j < N; j++, k--)
			Array[i][j] = k;
	}
	//print_array(Array, N);
	diagonal_sort(Array, N);


	cout << endl;
	print_array(Array, N);
}
