/*1. Среди N чисел найти количество таких, которые чётны и по модулю не меньше 10.
2. Дана последовательность из N чисел.Найти сумму всех элементов, которые не меньше своих индексов.
3. Дана матрица nxn.Найти номера строк, в которых встречаются нули.
4. Написать не возвращающую значение функцию, записывающую в третий параметр « - », 
если значение ровно одного из двух первых параметров « - », и « + » в противном случае.*/

/* Задание 1 (цикл)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N, counter = 0, x;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x % 2 == 0 && abs(x) >= 10)
            counter++;
    }
    cout << counter;
}*/

/* Задание 2 (массив)
#include <iostream>
using namespace std;
int main() {
    int N, S;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        if (arr[i] >= i)
            S += arr[i];
    }
    cout << S;
    delete arr;
} */

/* Задание 3 (массив)
#include <iostream>
using namespace std;
int main() {
    int n, counter0, theend = 0;
    cin >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i++) {
        counter0 = 0;
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 0)
                counter0++;
        if (counter0 != 0) {
            cout << i << endl;
            theend = 1;
        }
    }
    if (theend == 0)
        cout << "No zero";
}*/

#include <iostream>
#include <cmath>
using namespace std;
void change(int a, int b, char &ch) {
    if (abs(a) == a && abs(b) == b || abs(a) != a && abs(b) != b)
        ch = '+';
    else ch = '-';
}
int main() { //Проверка
    char ch = '0';
    change(-1, 2, ch);
    cout << ch;
}