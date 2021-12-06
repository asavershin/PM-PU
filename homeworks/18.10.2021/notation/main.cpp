#include <iostream>
int notation(int a, int n){
    unsigned int tmp, m;
    
    switch(n){
        case 2:
            tmp = a;
            m=0;

            while (tmp) {
                // m <<= 1;   //  m = m << 1; //  m *= 2;
                ++m;
                tmp >>= 1;
            }
            m = 1 << m;
            m = m>0 ? m-1 : 0;
            tmp = a;
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
                m >>= 1; // m/=2
            }
            break;
        case 3:
            tmp = a;
            m=1;

            while (tmp) {
                
                m*=3;
                tmp /= 3;
            }
            tmp = a;
        
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
               m/=3;
            }
            break;

        case 4:
            tmp = a;
            m=0;

            while (tmp) {
                ++m;
                tmp >>= 2; // tmp /= 4;
            }
            m = m>0 ? m-1 : 0;
            m = 1 << (2*m);

            tmp = a;
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
                m >>= 2;  //  m /= 4;
            }
            break;
        case 5:
            tmp = a;
            m=1;

            while (tmp) {
               
                m*=5;
                tmp /= 5;
            }
            tmp = a;
        
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
               m/=5;
            }
            break;
        case 6:
            tmp = a;
            m=1;

            while (tmp) {
                
                m*=6;
                tmp /= 6;
            }
            tmp = a;
        
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
               m/=6;
            }
            break;
        case 7:
            tmp = a;
            m=1;

            while (tmp) {
               
                m*=7;
                tmp /= 7;
            }
            tmp = a;
        
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
               m/=7;
            }
            break;
        case 8:
            tmp = a;
            m=0;

            while (tmp) {
                ++m;
                tmp >>= 3; // tmp /= 8;
            }
            m = m>0 ? m-1 : 0;
            m = 1 << (3*m);

            tmp = a;
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
                m >>= 3;  //  m /= 8;
            }

            break;
        case 9:
            tmp = a;
            m=1;

            while (tmp) {
              
                m*=9;
                tmp /= 9;
            }
            tmp = a;
        
            while (m) {
                std::cout << tmp / m;
                tmp %= m;
               m/=9;
            }
            break;
        case 10:
            tmp = a;
            m=1;

            while (tmp) {
                
                m*=10;
                tmp /= 10;
            }
            tmp = a;
    
            while (m) {
                    int digit = tmp / m;
                    if (digit<10)
                        std::cout << digit;
                    else
                        std::cout<< char('A');
                    tmp %= m;
                    m /=10;
                }
            break;
        case 11:
            tmp = a;
            m=1;

            while (tmp) {
              
                m*=11;
                tmp /= 11;
            }
            tmp = a;
        
            while (m) {
                    int digit = tmp / m;
                    if (digit<10)
                        std::cout << digit;
                    else
                        std::cout<< char('A'+ digit - 10);
                    tmp %= m;
                    m /=11;
                }
            break;
        case 12:
            tmp = a;
            m=1;

            while (tmp) {
               
                m*=12;
                tmp /= 12;
            }
            tmp = a;
            while (m) {
                    int digit = tmp / m;
                    if (digit<10)
                        std::cout << digit;
                    else
                        std::cout<< char('A'+ digit - 10);
                    tmp %= m;
                    m /=12;
            }
            break;
        case 13:
            tmp = a;
            m=1;
            while (tmp) {
            
                m*=13;
                tmp /= 13;
            }
            tmp = a;
            while (m) {
                    int digit = tmp / m;
                    if (digit<10)
                        std::cout << digit;
                    else
                        std::cout<< char('A'+ digit - 10);
                    tmp %= m;
                    m /=13;
            }
            break;
        case 14:
            tmp = a;
            m=1;
            while (tmp) {
                
                m*=14;
                tmp /= 14;
            }
            tmp = a;
    
            while (m) {
                    int digit = tmp / m;
                    if (digit<10)
                        std::cout << digit;
                    else
                        std::cout<< char('A'+ digit - 10);
                    tmp %= m;
                    m /=14;
            }
            break;
        case 15:
            tmp = a;
            m=1;

            while (tmp) {
                m*=15;
                tmp /= 15;
            }
    
            tmp = a;
            while (m) {
                int digit = tmp / m;
                if (digit<10)
                    std::cout << digit;
                else
                    std::cout<< char('A'+ digit - 10);
                tmp %= m;
                m /=15;
            }
            break;
        case 16:
            tmp = a;
            m=0;

            while (tmp) {
                ++m;
                tmp >>= 4; // tmp /= 16;
            }
            m = m>0 ? m-1 : 0;
            m = 1 << (4*m);

            tmp = a;
            while (m) {
                int digit = tmp / m;
                if (digit<10)
                    std::cout << digit;
                else
                    std::cout<< char('A' + digit - 10);
                tmp %= m;
                m >>= 4;  //  m /= 16;
            }
            break;
    }

    return 5;
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
    return 0;
}
