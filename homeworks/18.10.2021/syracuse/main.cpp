//
//  main.cpp
//  syracuse
//
//  Created by Александр Авершин on 24.10.2021.
//

#include <iostream>
void MaxSyracuse(int Num){
    int max = 1;
    int k = 0;
    while(Num != 1){
        if(Num > max)
            max = Num;
        if(Num % 2 == 0)
            Num>>=1;
        else{
            Num*=3;
            ++Num;
            }
        ++k;
        std::cout <<"("<< Num << ")" << std::endl;
    }
    std::cout << "Количество шагов:" << k;
    std::cout << std::endl;
    std::cout << "Максимум: " << max;
}
int main(int argc, const char * argv[]) {
    int a;
    std::cin >> a;
    std::cout << std::endl;
    MaxSyracuse(a);
    return 0;
}
