
#include <iostream>

#include <time.h>
unsigned long long circle(unsigned long long R)
{

    unsigned long long flag = 0;
    unsigned long long count = R;
    
    for( unsigned long long x = count; x > 0; x--){
        
        for ( unsigned long long y = 1; y <= R; y++ )
        {
            
            if (x * x + y * y > R * R)
            {
                --count;
                
                y = R+1;
        
            }
            if( x * x + y * y <= R * R)
            {
                ++flag;

            }
        }}
    std::cout << "Количество точек внутри и на окружности с целочисленными координатами:   ";
    return flag * 4  + 1 + 4 * (R);
}

int main() {
    unsigned long long R = 0;
    
    std::cout << "Введите радиус окружности:   ";
    std::cin >> R;
    time_t tic = time(NULL);
    std::cout << circle(R) << std::endl;
    time_t toc = time(NULL);
    std::cout << "Time = " << toc-tic;
    return 0;
}
