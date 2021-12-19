#include <iostream>
#include <numeric>
void ShiftArray(int *arr,int N, int shift){
    int NewPlace = 0;
    int OldPlace = 0;
    int tmp = 0;                 //Переменная для временного хранения самого первого замененного элемента
    int GCD= std::gcd(shift, N); //узнаем, сколько раз будет робигаться счетчик
    for (int k = 0; k < GCD; ++k) {
        
        tmp = arr[k];
        NewPlace = k;
        
        OldPlace = NewPlace + shift;
        if (OldPlace >= N)
            OldPlace -= N;
        while (OldPlace != k) {
            arr[ NewPlace ] = arr[ OldPlace ];
            NewPlace = OldPlace;
//          std::cout << OldPlace << "|";
            
            OldPlace = NewPlace + shift;
            if (OldPlace >= N)
                OldPlace -= N;
        }
        arr[NewPlace] = tmp;
    }
}
void print(int *arr, int N){
    for(int k = 0;k < N; ++k)
        std::cout <<"|"<< arr[k] << "|";
    std::cout << std::endl;
}
int main(int argc, const char * argv[]) {
    int N = 0;
    int shift = 0;
    std::cout << "Введите сначала размер массива(массив создается автоматически), а потом размер сдвига влево( >=0 )" << std::endl;
    std::cin >> N >> shift;
    shift %= N;
    int *arr = new int[N];
    for(int k = 0;k < N; ++k){
        arr[k] = rand()%10;
    }
    print(arr,N);
   
    ShiftArray(arr, N, shift);
    print(arr,N);
    delete[] arr;
    
    return 0;
}
