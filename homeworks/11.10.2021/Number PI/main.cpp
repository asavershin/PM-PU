#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>

double round(double Number, int N){// функция для округления
    double Mult = 1;
    for(int count = 0; count < N; count++)
        Mult*=10;
    Number = Number * Mult;
    return double((int((Number))%int((Mult*10))))/Mult;
}

double PI(int N, int *count){ // функция вычисления числа пи
    double result = 4; //Один из множителей по формуле Лейбница
    double j = 3.0; // знаменатель второго члена в ряде лейбница
    double mult = 1.0; // сумма ряда лейбница до нужного нам члена

    double first = 1;
    double second = 2;
    /* first и second  используются в дальнейшем, чтобы сравнивать значения найденного числа пи двух разных моментах ряда лейбница, чтобы узнать когда необходимый нам разряд перестанет изменять, а значит можно остановиться*/
    int k = 1;// счетчик
    for (; round(first,N) != round(second,N); k++){
        
        if(k % 2 == 0){
           
            mult = mult + 1.0/j;
            j = j+2.0;
        }
        else{
           
            mult = mult - 1.0/j;
            j = j+2.0;
        }


        if (k % 10 == 0){
            first = result*mult;
        }
        if ( k % 5 == 0 && k % 10 != 0 ){
            second = result * mult;
        }
        
    }
    *count = k;
    return round(first,N);
}
double Circle_PI (int *count){
    double R = 2; //радиус круга
    double x;
    double y;
    int flag1 = 0; // счетчик попаданий в круг
    for(int k = 0; k < *count; k++){
        x = double(rand()%20000)/10000; // подибраем рандомную координату x
        y = double(rand()%20000)/10000; // подибраем рандомную координату y
        if(x * x + y * y <= R * R )
            flag1++;
    }
    return 4.0*double(flag1)/(*count);
}
int main(int argc, const char * argv[]) {
    int N;
    int *count = new int;
    
    std::cout << "Введите точность вычисления числа PI: " << std::endl;
    std::cin >> N;
    std::cout <<std::fixed<< std::setprecision(N);
    std::cout <<"PI = "<<PI(N, count) << "";
    std::cout <<std::endl<<"Количество слагаемых в ряду: "<< *count;
    std::cout << std::endl;
    std::cout <<std::fixed<< std::setprecision(N+4);
    std::cout << "Число ПИ вычисленное с помощью коружности: " << Circle_PI(count) << std::endl;
    return 0;
}
