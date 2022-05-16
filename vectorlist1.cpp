#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;
int main() {
	int a;
	ifstream fin("input.txt");
	vector<int> Vector; //Б
	list <int> List; //А
	while (fin >> a) {
		Vector.push_back(a); //Б
		List.push_back(a); //А
	}
	/*------------------------------ Задача А -----------------------------*/
	cout << "Задача А: Вставить нулевые элементы до и после последнего четного." << endl;
	list<int>::iterator mem_iter;
	for (list<int>::iterator iter = List.begin(); iter != List.end(); iter++)
		if (*iter % 2 == 0)
			mem_iter = iter;
	List.insert(mem_iter, 0);
	List.insert(++mem_iter, 0);
	for (list<int>::iterator iter = List.begin(); iter != List.end(); iter++)
		cout << *iter << ' ';
	/*------------------------------ Задача Б -----------------------------*/
	cout << endl << "Задача А: Вставить нулевые элементы до и после последнего четного." << endl;
	if (Vector[0] > Vector[1])
		Vector[Vector.size() - 1] = Vector[1];
	else Vector[Vector.size() - 1] = Vector[0];
	for (int i = 0; i < Vector.size(); i++)
		cout << Vector[i] << ' ';
}
