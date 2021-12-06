#include <iostream>
#include "matrix.h"

int main() {
    double **E,**I;
    try {
        int size;
        std::cout << "Введите размерность матрицы для которой будем считать определитель и обратную матрицу: ";
        std::cin >> size;
        std::cout <<std::endl<< "Введите матрицу" << std::endl;
        E = inputMatrix<double>(size, size);
        std::cout << "Определитель = " << det(E, size) << std::endl;
        I = inv(E, size);
        print(I, size, size, "Обратная матрица \n");
    }
    catch (const char *error) {
        std::cout << "Error: " << error << std::endl;
    }
    catch (...) {
        std::cout << "Unknown error." << std::endl;
    }
    system("pause");
    return 0;
}
