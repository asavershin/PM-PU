#include <iostream>
#include <cmath>
void notation(int a, int n){
    unsigned int tmp = a, m = 0;
    
    
    
    while (tmp) {
        ++m;
        tmp /= n; // tmp /= 16;
    }
    m = m>0 ? m-1 : 0;
    m = pow(n, m);
    tmp = a;
    while (m) {
        int digit = tmp / m;
        if (digit<10)
            std::cout << digit;
        else
            std::cout<< char('A' + digit - 10);
        tmp %= m;
        m /= n;  //  m /= 16;
    }
}
int main(int argc, const char * argv[]) {
    unsigned int x;
    int n;

    do{
        std::cout << "Введите положительное число в десятичной системе счисления: ";
        std::cin >> x;
        
    }
    while(x<=0);

    do{
        std::cout << "Введите систему счисления(2-16) в которую переводим число:";
        std::cin >> n;
        
    }
    while(n<2 || n>16);
    notation(x,n);
    std::cout << "\n";
    return 0;
}
