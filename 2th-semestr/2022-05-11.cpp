//----------------------------------0-------------------------
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
void display(stack<char> S1, stack<char> S2) {
	stack<char> Temp;
	cout << "1: ";
	while (!S1.empty()) {
		cout << S1.top();
		Temp.push(S1.top());
		S1.pop();
	}
	while (!Temp.empty()) {
		S1.push(Temp.top());
		Temp.pop();
	}
	cout << endl << "2: ";
	while (!S2.empty()) {
		cout << S2.top();
		Temp.push(S2.top());
		S2.pop();
	}
	cout << endl;
	while (!Temp.empty()) {
		S2.push(Temp.top());
		Temp.pop();
	}
}
int main() {
	ifstream fin("input.txt");
	string Temp;
	int N;
	fin >> Temp >> N;
	stack<char> Wagons, Tunnel_1, Tunnel_2;
	for (int i = 0; i < Temp.size(); i++)
		Wagons.push(Temp[i]);
	for (int i = 0; fin >> Temp; i++)
		if (Temp[0] == Wagons.top()) {
			if (Temp[1] == '1')
				Tunnel_1.push(Wagons.top());
			else Tunnel_2.push(Wagons.top());
			Wagons.pop();
			display(Tunnel_1, Tunnel_2);
			cout << endl;
		}
}
