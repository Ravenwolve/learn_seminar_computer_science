#include <iostream>

using namespace std;

int main()
{
    short day;
    string height;
    cout << "Enter the number of the day on a week: " << endl;
    cin >> day;
    cout << "Enter the 'N' (numerator) or 'D' (denomirator): " << endl;
    cin >> height;
    if (height == "N" && day > 0 && day < 7)
    {
        switch (day)
        {
        case 1:
            cout << "08:20 - 09:50 | " << endl << "10:00 - 11:35 | Informatics and programming (lecture) | 333" << endl << "12:05 - 13:40 | Informatics and programming (practice) | 415" << endl;
            //break;
        case 2:
            cout << "08:20 - 09:50 | English language (practice) | 304" << endl << "10:00 - 11:35 | Mathematical analysis (lecture) | 333" << endl << "12:05 - 13:40 | Algebra and geometry (practice) | 302" << endl;
            //break;
        case 3:
            cout << "08:20 - 09:50 | Algebra and geometry (lecture) | 333" << endl << "10:00 - 11:35 | Mathematical analysis (practice) | 304" << endl << "12:05 - 13:40 | Physical culture (practice) | Gym" << endl;
            //break;
        case 4:
            cout << "08:20 - 09:50 | " << endl << "10:00 - 11:35 | English language (practice) | 302" << endl << "12:05 - 13:40 | Introduction to the specialty (practice) | 310" << endl;
            //break;
        case 5:
            cout << "08:20 - 09:50 | " << endl << "10:00 - 11:35 | " << endl << "12:05 - 13:40 | History (lecture) | 424" << endl << "13:50 - 15:25 | Russian language (lecture) | 333" << endl << "15:35 - 17:10 | History (practice) | 313" << endl;
            //break;
        case 6:
            cout << "empty" << endl;
            //break;
        }
    }
    else if (height == "D" && day > 0 && day < 7)
    {
        switch (day)
        {
        case 1:
            cout << "08:20 - 09:50 | " << endl << "10:00 - 11:35 | Informatics and programming (lecture) | 333" << endl << "12:05 - 13:40 | Informatics and programming (practice) | 415" << endl;
            break;
        case 2:
            cout << "08:20 - 09:50 | English language (practice) | 304" << endl << "10:00 - 11:35 | Mathematical analysis (lecture) | 333" << endl << "12:05 - 13:40 | Algebra and geometry (practice) | 302" << endl;
            break;
        case 3:
            cout << "08:20 - 09:50 | Algebra and geometry (lecture) | 333" << endl << "10:00 - 11:35 | Mathematical analysis (practice) | 304" << endl << "12:05 - 13:40 | Physical culture (practice) | Gym" << endl;
            break;
        case 4:
            cout << "08:20 - 09:50 | Informatics and programming (practice) | 304" << endl << "10:00 - 11:35 | English language (practice) | 302" << endl << "12:05 - 13:40 | Introduction to the specialty (lecture) | 310" << endl;
            break;
        case 5:
            cout << "08:20 - 09:50 | " << endl << "10:00 - 11:35 | " << endl << "12:05 - 13:40 | History (lecture) | 424" << endl << "13:50 - 15:25 | Russian language (practice) | 312" << endl;
            break;
        case 6:
            cout << "empty" << endl;
            break;
        }
    }
    else
    {
        cout << "null" << endl;
    }
}