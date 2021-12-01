#include <iostream>
using namespace std;
double fact(int x);
double f(double x);
int main()
{
    const double eps = 1e-6;
    double s = 0;
    for (int i = 0; f(i) > eps; i++)
    {
        s += f(i);
    }
    cout << s << endl;
}
double fact(int x)
{
    int fact = 1;
    for (int i = 1; i <= x; i++)
        fact *= i;
    return fact;
}
double f(double x)
{
    return (x + 3) / fact(x);
}