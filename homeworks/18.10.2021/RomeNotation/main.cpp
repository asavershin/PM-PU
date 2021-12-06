
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void RomeNotation(unsigned int x){// функция по преобразованию чисел в римское представление
    int M = x/1000;
    x %= 1000;
    for (int k = 0; k < M; ++k)// вывод разрядов тысяч
        cout << "M";
    int C = x/100;
    switch (C){// условия для вывода разрядов с сотнями
        case 0:
            break;
        case 1:
            cout << "C";
            break;
        case 2:
            cout << "CC";
            break;
        case 3:
            cout << "CCC";
            break;
        case 4:
            cout << "CD";
            break;
        case 5:
            cout << "D";
            break;
        case 6:
            cout << "DC";
            break;
        case 7:
            cout << "DCC";
            break;
        case 8:
            cout << "DCCC";
            break;
        case 9:
            cout << "CM";
            break;
    }
    x %= 100;
    
    int X = x/10;
    switch (X){// вывод десятков
        case 0:
            break;
        case 1:
            cout << "X";
            break;
        case 2:
            cout << "XX";
            break;
        case 3:
            cout << "XXX";
            break;
        case 4:
            cout << "XL";
            break;
        case 5:
            cout << "L";
            break;
        case 6:
            cout << "LX";
            break;
        case 7:
            cout << "LXX";
            break;
        case 8:
            cout << "LXXX";
            break;
        case 9:
            cout << "XC";
            break;
    }
    x %= 10;
    int I = x;// выовд единиц
    switch (I){
        case 0:
            break;
        case 1:
            cout << "I";
            break;
        case 2:
            cout << "II";
            break;
        case 3:
            cout << "III";
            break;
        case 4:
            cout << "IV";
            break;
        case 5:
            cout << "V";
            break;
        case 6:
            cout << "VI";
            break;
        case 7:
            cout << "VII";
            break;
        case 8:
            cout << "VIII";
            break;
        case 9:
            cout << "IX";
            break;
    }
    
}

int main(int argc, const char * argv[]) {
    unsigned int x = 0;
    do{
        cout << "Введите число(1-3999), которое хотите перевести в римскую систему счисления: ";
        cin >> x;
        cout << endl;
    }
    while(x<=1 && x>=3999);
    cout << "число " << x <<  " в римской системе счисления: ";
    RomeNotation(x);
    cout << endl;
    return 0;
}
