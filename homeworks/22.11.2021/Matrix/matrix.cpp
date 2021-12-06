#include <iostream>
#include "matrix.h"

double** linspace(double first, double last, int n) {
    if (n<2)
        throw "linspace arguments error (n<2)";
    
    double step = (last - first) / (n-1);

    double** M = createMatrix<double>(1, n);
    for (int i = 0; i < n; ++i)
        M[0][i] = first + i * step;
    return M;
}
double det(double** M, int size) {
    double** A = createMatrix<double>(size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A[i][j] = M[i][j];
        }
    }
    
    int permut = 0;
    int count = 0;
    double mult = 1;
    for (int k = 0; k < size-1; ++k) {
        count = 1;
        if(!A[k][k]){
            for(;k+count < size; ++count){
                if(A[k+count][k] != 0)
                    break;
            }
            if(k + count == size)
                return 0;
            else
                std::swap(A[k], A[k+count]);
            ++permut;
        }
        for(int j = k+1; j < size; ++j){
            mult = A[j][k];
            for(int i = k; i < size; ++i){
                A[j][i] = A[j][i] - A[k][i]*mult/A[k][k];
            }
        }
    }
    double det = 1;
    for (int i = 0; i < size; ++i) det *= A[i][i];
    deleteMatrix(A, size);
    if (permut & 1) det = -det;
    return det;
}

double **inv(double **M, int size) {
    double** A = createMatrix<double>(size, size);
    double** E = eye<double>(size);
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A[i][j] = M[i][j];
        }
    }
    
    int count = 0;
    double mult = 1;
    for (int k = 0; k < size-1; ++k) {
        count = 1;
        if(!A[k][k]){
            for(;k+count < size; ++count){
                if(A[k+count][k] != 0)
                    break;
            }
            if(k + count == size)
                return M;
            else{
                std::swap(A[k], A[k+count]);
                std::swap(E[k], E[k+count]);
            }
        }
        for(int j = k+1; j < size; ++j){
            mult = A[j][k];
            for(int i = 0; i < size; ++i){
                E[j][i] = E[j][i] - E[k][i]*mult/A[k][k];
                A[j][i] = A[j][i] - A[k][i]*mult/A[k][k];
            }
        }
    }
    double det = 1;
    for (int i = 0; i < size; ++i) det *= A[i][i];
    try {
        if(det == 0){
            throw;
            
        }
    }
    catch(...){
        std::cout << "Нет обратной матрицы" << std::endl;
        return zeros<double>(size, size);
    }
    
    for (int k = size - 1; k >= 0; --k) {
            for (int i = k - 1; i >= 0; --i) {
                double n = A[i][k];
                for (int j = 0; j < size; ++j) {
                    E[i][j] = E[i][j] - (E[k][j] / A[k][k]) * n;
                    A[i][j] = A[i][j] - (A[k][j] / A[k][k]) * n;
                }
            }
        }
    for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    E[i][j] /= A[i][i];
                }
            //}
        }
    deleteMatrix(A, size);
    return E;
}
