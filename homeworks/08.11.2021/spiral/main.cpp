#include <iostream>
void spriral(int n, int m){
    int arr[n][m];
    int Number = 1;
    int k = 0;
    int flag = n*m;
    while(Number <= flag){
        
        for(int count = k; count < m-k && Number <= flag; ++count)
            arr[k][count] = Number++;
        
        for(int count = k+1; count < n-k && Number <= flag;++count)
            arr[count][m-k-1] = Number++;
        for(int count = m-k-2; count >= k && Number <= flag; --count)
            arr[n-k-1][count] = Number++;
        for(int count = n-k-2; count >= k+1 && Number <= flag;--count)
            arr[count][k] = Number++;
        ++k;
    }
    std::cout << std::endl;
    for(int k = 0; k < n ; ++k){
        for(int j = 0; j < m; ++j)
            std::cout << arr[k][j]<<" ";
        std::cout << std::endl;
    }
}
int main(int argc, const char * argv[]) {
    int n,m;
    n = 0;
    m = 0;
    std::cout << "Введите размерность двумерной матрицы: ";
    std::cin >> n >> m;
    spriral(n,m);
    return 0;
}
