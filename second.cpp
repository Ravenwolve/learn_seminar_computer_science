#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    //ВЫЧИСЛЕНИЕ РАССТОЯНИЯ ОТ ТОЧКИ ДО ОКРУЖНОСТИ
    double xt, yt, xo, yo, r, l, x, y; // xt & yt - координаты точки, xo & yo - координаты окружности, r - радиус, l - расстояние
    cout << "Enter the x and y point coordinate: " << endl;
    cin >> xt >> yt;
    cout << "Enter the x and y cicrle center coordinate: " << endl;
    cin >> xo >> yo;
    cout << "Enter the radius of circle: " << endl;
    cin >> r;
    x = abs(xt) + abs(xo);
    y = abs(yt) + abs(yo);
    l = sqrt(pow(x, 2) + pow(y, 2)) - r;
    cout << "The legth is " << l << endl;
}