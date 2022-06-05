#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int numbers_amount(int N) {
	int count = 0;
	for (; N > 0; count++)
		N /= 10;
	return count;
}
int main() {
	int N;
	cin >> N;
	set<int> Set;
	for (int i = 0; i < N; i++)
		Set.insert(rand() % 1000);
	cout << *Set.begin() << ' ' << *(--Set.end()); //проверка первого и последнего
	set<int> Numbers_FL;
	for (int i = 0, num1 = *Set.begin(); i < numbers_amount(*Set.begin()); i++, num1 /= 10)
		for (int j = 0, num2 = *(--Set.end()); j < numbers_amount(*(--Set.end())); j++, num2 /= 10)
			if (num1 % 10 == num2 % 10)
				Numbers_FL.insert(num1 % 10);
	for (auto S = Set.begin(); S != Set.end(); S++)
		for (N = *S ; N > 0; N /= 10)
			remove_if(Numbers_FL.begin(), Numbers_FL.end(), [N](int a) { return a == N % 10; });
	for (auto Number : Numbers_FL)
		cout << Number << ' ';
}
