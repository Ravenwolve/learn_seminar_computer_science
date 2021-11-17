//Даны радиус круга и сторона квадрата. Если данные корректны, определить чья площадь меньше
#include <iostream>
#include <cmath>

using namespace std;

void s_srav(double r, double a);
int main()
{
	double r, a;
	cin >> r >> a;
	s_srav(r, a);
}
void s_srav(double r, double a)
{
	double pi = 4*atan(1);
	if (r > 0 && a > 0)
	{
		if (pi*r*r < a*a)
			cout << "S круга меньше S квадрата" << endl;
		if (pi*r*r > a*a)
			cout << "S квадрата меньше S круга" << endl;
		else cout << "S равны" << endl;
	}
	else cout << "Данные некорректны" << endl;
}
