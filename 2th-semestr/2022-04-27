//---------------------------------------------(3)-------------------------
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
void sortqueue(queue<int> &Q) {
    stack<int> St;
    queue<int> Q2;
    while (!Q.empty()) {
        if (Q.front() % 2 != 0) {
            St.push(Q.front());
            Q.pop();
        }
        else {
            Q2.push(Q.front());
            Q.pop();
        }
    }
    while (!Q2.empty()) {
        Q.push(Q2.front());
        Q2.pop();
    }
    while (!St.empty()) {
        Q.push(St.top());
        St.pop();
    }
}
int main() {
    ifstream fin("input.txt");
    queue<int> Q;
    int i;
    while (fin >> i) //заполнить стек из файла
        Q.push(i);
    fin.close();
    sortqueue(Q);
    while (!Q.empty()) { //вывести очередь
        cout << Q.front() << '\n';
        Q.pop();
    }
}

