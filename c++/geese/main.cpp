#include <iostream>

int main() {
    int n2;
    do{
        std::cout << "how many paws?";
        std::cin >> n2;
    }while(n2 % 2 != 0);
    std::cout << std::endl;
    for (int r = 0; 4 * r <= n2; ++r){
        std::cout << r << "-rabbits " << (n2 - 4 * r)/2 << "-geese" << std::endl;
    }
    
    return EXIT_SUCCESS;
}
