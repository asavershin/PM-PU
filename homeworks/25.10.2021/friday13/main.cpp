#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int NextFriday(int Day, int Month){
    int a;
    int y;
    int m;
    int Year = 0;
    int JD;
    
    do {
        Year++;
        a = (14 - Month) / 12; y = Year + 4800 - a; m = Month + 12 * a - 3;
        JD = (Day + 365 * y + y / 4 - y / 100 + y / 400 + (153 * m+2) / 5 - 32045);
        cout << JD << endl;
    } while (JD % 7 != 4);
    
    return Year;
}
double Chance(){
    int Day=1;
    int Month=1;
    int Year = 0;
    int a = (14 - Month) / 12;
    int y = 4800 + Year - a;;
    int m = Month + 12 * a - 3;
    int JD = Day + 365 * y + y / 4  - y / 100 + y / 400 + (153 * m + 2) / 5 - 32045;
    int count1 = 0;
    int count2 = 0;
    
    while (JD % 7 != 4) {
        ++JD;
    }
    int aa,b,c,d,e,mm;
    do {
        ++count1;
        
        
        aa = JD + 32044;
        b = (4 * aa + 3) / 146097;
        c = aa - (146097 * b) / 4;
        d = (4 * c + 3) / 1461;
        e = c - (1461 * d) / 4;
        mm = (5 * e + 2) / 153;
        if ((e - (153 * mm + 2) / 5 + 1) == 13)
            ++count2;
        JD += 7;
    } while (JD < 2000000);
    return double(count2)/double(count1);
}

int Number(){
    int Day=1;
    int Month=1;
    int Year = 1901;
    int a = (14 - Month) / 12;
    int y = 4800 + Year - a;;
    int m = Month + 12 * a - 3;
    int JD = Day + 365 * y + y / 4  - y / 100 + y / 400 + (153 * m + 2) / 5 - 32045;
    while (JD % 7 != 4) {
        ++JD;
    }
    
    int Number = 0;
    int aa,b,c,d,e,mm;
    
    do {
        aa = JD + 32044;
        b = (4 * aa + 3) / 146097;
        c = aa - (146097 * b) / 4;
        d = (4 * c + 3) / 1461;
        e = c - (1461 * d) / 4;
        mm = (5 * e + 2) / 153;
        if ((e - (153 * mm + 2) / 5 + 1) == 13)
            ++Number;
        JD += 7;
    } while (JD < 2451911);
    return Number;
}

int main() {


    cout << "Вероятность того, 13 число придется на пятницу:  " << Chance()*100 << "%";
    cout << endl;
    cout << "Количество пятниц 13 в ХХ веке: " << Number();
    cout << endl << endl;
}
