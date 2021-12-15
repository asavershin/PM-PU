#include <iostream>
int* ShiftArray(int *arr,int N, int shift){
    int *M = new int;
    int shift2;
    if(shift > N)
        shift%=N;
    for (int k = 0; k < N; ++k){
        if(shift + k < N)
            shift2 = shift+k;
        else
            shift2 = shift+k-N;
        M[k] = arr[shift2];
    }
    delete []arr;
    return M;
}
void print(int *arr, int N){
    for(int k = 0;k < N; ++k)
        std::cout <<"|"<< arr[k] << "|";
    std::cout << std::endl;
}
int main(int argc, const char * argv[]) {
    int N = 0;
    int shift = 0;
    std::cout << "Введите сначала размер массива(она задается сам), а потом размер сдвига влево" << std::endl;
    std::cin >> N >> shift;
    int *Arr = new int;
    for(int k = 0;k < N; ++k)
        Arr[k] = rand()%10;
    print(Arr,N);

    Arr = ShiftArray(Arr, N, shift);
    print(Arr,N);
    
    return 0;
}
