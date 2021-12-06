#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int NextFriday(int Day, int Month){
    int a;
    int y;
    int m;
    int Year = 2020;
    int JD;
    
    do {
        Year++;
        a = (14 - Month) / 12; y = Year - a; m = Month + 12 * a - 2;
        JD = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    } while (JD % 7 != 5);
    
    return Year;
}

int main() {

    int Day , Month;
    cout << "Введите день: ";
    cin >> Day;
    cout << "Введите месяц(1-12): ";
    cin >> Month;
    cout << "Год, когда в указанную дату будет пятница: " << NextFriday(Day, Month);
    cout << endl << endl;
}
