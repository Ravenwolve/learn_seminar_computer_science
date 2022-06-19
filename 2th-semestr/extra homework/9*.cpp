#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//Даны числа, найти все группы из двух и более чисел, которые состоят из одних и тех же цифр с учётом повторов, например:
//ввод: 
//1 192 991 10 291 101 - 110 0 921 92 91 919 19
//вывод: 
//192, 291, 921
//101, -110
//91, 19
int main() {
	ifstream fin("input.txt");
	vector<string> V;
	for (string s; fin >> s; V.push_back(s));
	int counter = 0;
	bool boolean = 1;
	for (vector<string>::iterator iter_1 = V.begin(); iter_1 != V.end(); iter_1++) {
		for (vector<string>::iterator iter_2 = iter_1 + 1; iter_2 != V.end(); iter_2++)
			if ((*iter_1).length() == (*iter_2).length()) {
				for (int i = 0; i < (*iter_1).length(); i++) {
					string temp = *iter_2; // запоминаем, чтобы ее портить
					for (int j = 0; j < (*iter_2).length(); j++)
						if ((*iter_1)[i] == temp[j]) {
							counter++; // счетчик одинаковых цифр (который должен быть равен длине числа)
							temp[j] = ' '; // заменяется цифра на пробел, чтобы не сравнивать с ней же снова
							break; // выход из цикла, чтобы при первой встречной такой же цифре перестать считать
						}
				}
				if (counter == (*iter_1).length()) {
					if (boolean) { // выводит первый элемент (с которым мы сравниваем) один раз, для этого нужен флажок
						cout << *iter_1 << ", ";
						boolean = 0;
					}
					cout << *iter_2 << ", ";
					iter_2 = V.erase(iter_2);
					counter = 0;
				}
			}
		boolean = 1;
		cout << endl;
	}
	// Программа не работает корректно, пытался найти ошибку, но идея вроде верная
}
