


#include <iostream>
#include <cmath>                                                            //подключаем библиотеку, чтобы использовать функцию abs(...)

void rhombus(int n, int m)                                                  //функция выводящая ромбики
{
    
    for ( int k = 1; k <= (2 * n - 1); k++ )                                //перемещаемся от первой до 2*n-1 строки
    {
        float expr = fabs((n - k) % n);
        
        for ( int j = 1; j <= m; j++ )                                      //формируем сразу строку сразу для всех ромбов
        {
            
            for (int s = 0; s <  expr; s++ )                   //выводит количество пробелов слева от звёзд
                std::cout << ' ';
            for (int d = 0; d < ( ( n - 1 ) - expr ); d++ )   //выводит звёзды слева от центральной звезды
                std::cout << '*';
            std::cout << '*';                                               //выводится центральная звезда
            for (int d = 0; d < ( ( n - 1 ) - expr ); d++ )   // выводит звёзды справа от центральной звезды
                std::cout << '*';
            for (int s = 0; s < expr ; s++ )                   //выводит количество пробелов справа от звезд
                std::cout << ' ';
           
            
            
            
        }
        std::cout << std::endl;
    }
}

int main() {
    
    int n = 0;
    int m = 0;
    std::cout << "Введите число n, которое будет соответовавать глубине ромба по формуле 2n-1:  ";
    std::cin >> n;
    std::cout << std::endl << "Введите количество ромбов:   ";
    std::cin >> m;
    std::cout << std::endl;
    
    
    rhombus( n , m );
    
    
    
    
    return 0;
}
