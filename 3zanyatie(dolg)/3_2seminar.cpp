#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool s_bool(double a);
void s_sqrt(double a);

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	cin >> a >> b >> c;
	s_sqrt(a); s_sqrt(b); s_sqrt(c);
}



bool s_bool(double a)
{
	if (a >= 0)
		return true;
	else return false;
}
void s_sqrt(double a)
{
	if (s_bool(a) == true)
		cout << fixed << setprecision(4) << sqrt(a) << ' ';
	else cout << a << ' ';
}