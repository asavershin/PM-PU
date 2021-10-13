
#include <iostream>
#include <cmath>

double sum (double x, int n)
{
    double result = 0;
    double arcsin = x;
    
    for (int k = 0; k < n; k++)
    {
        
        result = result + sin(arcsin);
        arcsin = sin(arcsin);
    }
    
    std::cout << std::endl;
    
    return result;
}
int main() {
    
    double x; // аргумент
    int n; // число слагаемых в ряду
    
    std::cout << "Введите аргумент и число слагаемых в ряду:    " << std::endl;
    std::cin >> x >> n;
    std::cout<< std::endl << sum(x, n) << std::endl;
    
    return 0;
}
