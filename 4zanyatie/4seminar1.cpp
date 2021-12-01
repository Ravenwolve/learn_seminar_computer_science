#include <iostream>
using namespace std;
double absol(double a);
void midpoint(double x1, double y1, double x2, double y2);
int main()
{
    setlocale(LC_ALL, "Russian");
    int N, counter1 = 0, counter2 = 0, counter3 = 0;
    double x1, y1, x2, y2;
    double* px1 = &x1, * py1 = &y1, *px2 = &x2, *py2 = &y2;
    cout << "Введите N - количество отрезков: ";
    cin >> N;
    for (int i = 1; i <= N; i++, cout << endl)
    {
        cout << "Введите координаты x1, y1 и x2, y2 соответственно: ";
        cin >> *px1 >> *py1 >> *px2 >> *py2;
        if (x1 == x2 || y1 == y2)
        {
            if (x1 == x2 && y1 == y2)
                cout << "!!!Это не отрезок, а точка!!!" << endl;
            else if (y1 == y2)
            {
                cout << i << "-й отрезок направлен горизонтально" << endl;
                counter1++;
            }
            else
            {
                cout << i << "-й отрезок направлен вертикально" << endl;
                counter2++;
            }
        }
        else
        {
            cout << i << "-й отрезок направлен наклонно и его средняя точка лежит на ";
            midpoint(x1, y1, x2, y2);
            counter3++;
            
        }
    }
    cout << "Горизонтаьных отрезков - " << counter1 << ", вертикальных - " << counter2 << ", наклонных - " << counter3 << endl;
}
double absol(double a)
{
    if (a < 0)
        return -a;
    else return a;
}
void midpoint(double x1, double y1, double x2, double y2)
{
    cout << '(' << (absol(x1) + absol(x2)) / 2 << ';' << (absol(y1) + absol(y2)) / 2 << ')';
}