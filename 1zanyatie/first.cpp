#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	//ВЫЧИСЛЕНИЕ ПЕРИМЕТРА И ПЛОЩАДИ ПРЯМОУГОЛЬНОГО ТРЕУГОЛЬНИКА ПО ГИПОТЕНУЗЕ И УГЛУ!
	double P, S, a, b, c, x; // P - периметр, S - площадь, a & b - катеты, c - гипотенуза, x - угол
	cout << "Enter the hypotenuse value: " << endl;
	cin >> c;
	cout << "Enter the angle value: " << endl;
	cin >> x;
	a = c * abs(cos(x));
	b = sqrt(pow(c, 2) - pow(a, 2));
	S = 0.5 * a * c * sin(x);
	P = a + b + c;
	cout << "The perimeter is " << P << endl << "The square is " << S << endl;
}