/*1. Читать пары чисел, пока не попадётся пара из одинаковых.Определить процент пар, в которых первое число больше.
2. Дана последовательность из N чисел.Заменить все элементы, расположенные между первым отрицательным и последним максимальным, нулями.
Гарантируется, что хотя бы один отрицательный элемент в последовательности имеется.
3. Дана матрица nxn. Циклически сдвинуть элементы последнего столбца на один назад, т.е.элемент из второй строки должен оказаться первой строке, 
элемент третьей строки на второй и так далее, элемент первой строки должен оказаться на последней строке.
4. Написать функцию, раскладывающую число на простые множители. Функция должна принимать число, 
а результатом работы будет массив из множителей в любом порядке, но в нужном количестве(чтобы при перемножении получалось исходное число) и его размер.*/
// Задание 1.
#include <iostream>
using namespace std;
int main() {
	int a, b;
	double counterA = 0, counter_all = 0;
	while (cin >> a >> b && a != b) {
		if (a > b)
			counterA++;
		counter_all++;
	}
	cout << counterA / counter_all * 100 << '%';
}
// Задание 2
#include <iostream>
using namespace std;
int main() {
	int N, firstnegative = -1, lastmax = 0, maxarr = 0, flag = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (firstnegative == -1 && arr[i] < 0)
			firstnegative = i;
		if (flag = 0) {
			maxarr = arr[i];
			flag = 1;
		}
		if (arr[i] >= maxarr) {
			maxarr = arr[i];
			lastmax = i;
		}
	}
	for (int i = firstnegative + 1; i < lastmax; i++)
		arr[i] = 0;
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
}
// Задание 3
#include <iostream>
using namespace std;
int main() {
	int n, point;
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < n; i++) {
		point = arr[i][0];
		for (int j = 0; j < n; j++) {
			if (j > 0 && j < n)
				arr[i][j - 1] = arr[i][j];
		}
		arr[i][n - 1] = point;
	}
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < n; j++, cout << ' ')
			cout << arr[i][j];
}
//Задание 4
#include <iostream>
using namespace std;
int main() {
	int N, N1, counter = 0;
	cin >> N;
	N1 = N;
	for (int i = 2; i <= N; i++) {
		while (N % i == 0) {
			N /= i;
			counter++;
		}
	}
	N = N1;
	int* arr = new int[counter];
	int j = 0;
	for (int i = 2; i <= N; i++) {
		while (N % i == 0) {
			N /= i;
			arr[j] = i;
			j++;
		}
	}
	for (int i = 0; i < counter; i++)
		cout << arr[i] << ' ';
}