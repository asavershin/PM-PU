//
//  main.cpp
//  tower
//
//  Created by Александр Авершин on 08.11.2021.
//

#include <iostream>

void FloorNumber(int room){
    int floor = 1;
    int number;
    int floor2 = 0;
    while(room - floor*floor > 0){
        room -= floor * floor;
        ++floor;
        
    }
    
    for(int k = 1;k<floor;++k){
        floor2+=k;
        
    }
    floor2 += (room+floor-1)/floor;
    
    number = room % floor;
    if(number == 0){
        number = floor;
    }
    
    std::cout << "этаж: " << floor2 <<std::endl << "Номер комнаты по счету слева: " << number<<std::endl<<std::endl;
    
}

int main(int argc, const char * argv[]) {
    int Number;
    std::cout << "Введите номер комнаты: ";
    std::cin >> Number;
    
    FloorNumber(Number);
    return 0;
}
