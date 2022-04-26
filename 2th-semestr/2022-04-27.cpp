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

//---------------------------(4)--------------------------------------
//IAF - Insert After First
void IAF_Stack(stack<int>& Stack) {
    stack<int> temp;
    int min = Stack.top();
    while (!Stack.empty()) {
        if (Stack.top() < min)
            min = Stack.top();
        temp.push(Stack.top());
        Stack.pop();
    }
    Stack.push(temp.top());
    temp.pop();
    Stack.push(min);
    while (!temp.empty()) {
        Stack.push(temp.top());
        temp.pop();
    }
    while (!Stack.empty()) {
        temp.push(Stack.top());
        Stack.pop();
    }
    Stack = temp;
}
void IAF_Queue(queue<int>& Queue) {
    int min = Queue.back();
    for (int i = 0, size = Queue.size(); i < size; i++) {
        if (Queue.front() < min)
            min = Queue.front();
        if (i == 1)
            Queue.push(min);
        Queue.push(Queue.front());
        Queue.pop();
    }
}
void IAF_Vector(vector<int>& Vector) {
    int min = Vector[0];
    vector<int>::iterator iter = Vector.begin() + 1;
    for (int i = 1; i < Vector.size(); i++)
        if (Vector[i] < min)
            min = Vector[i];
    Vector.insert(iter, min);
}
void IAF_List(list<int>& List) {
    int min = List.back();
    auto iter = List.begin();
    for (auto i = iter; i != List.end(); i++)
        if (*i < min)
            min = *i;
    List.insert(iter, min);
}
