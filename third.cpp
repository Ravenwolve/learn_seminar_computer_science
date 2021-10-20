#include <iostream>
using namespace std;

int main()
{
    double val;
    cout << "Enter the value: " << endl;
    cin >> val;
    val > 0 ? cout << "The sign is positive (+)" : val < 0 ? cout << "The sign is negative (-)" : cout << "This is zero (0)";
}