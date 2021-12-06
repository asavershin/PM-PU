#include <cstdlib>
#include <iostream>
#include <vector>
void HoleSearch(int N){
    std::vector <int> array;
    for (int k = 0; k<=N; ++k){
        array.push_back(k);
    }
    int arr[N];
    int rand;
    for(int k = 0,num = N+1; k < N; ++k,--num){
        rand = std::rand() % num;
        arr[k] = array[rand];
        array.erase(array.begin() + rand);
    }
    std::cout << "Массив: ";
    for (int k = 0; k < N; ++k){
        std::cout <<"{"<< arr[k]<< "}";
    }
    int sum1 = 0;
    int sum2 = (1+N)*N/2;
    for(int k = 0; k < N; ++k){
        sum1 += arr[k];
    }
    std::cout << std::endl << "Отсутствущее число: " << sum2-sum1;
}
int main(int argc, const char * argv[]) {
    std::cout << "Введите длину массива: ";
    int N;
    std::cin >> N;
    HoleSearch(N);
    return 0;
}
