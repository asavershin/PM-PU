#include <iostream>
#include <string>
#include <vector>
std::string Thirst(int num){
    std::string Number;
    switch (num){
        case 0:
            break;
        case 1:
            Number = "сто ";
            break;
        case 2:
            Number = "двести ";
            break;
        case 3:
            Number = "триста ";
            break;
        case 4:
            Number = "четыреста ";
            break;
        case 5:
            Number = "пятьсот ";
            break;
        case 6:
            Number = "шестьсот ";
            break;
        case 7:
            Number = "семьсот ";
            break;
        case 8:
            Number = "восемьсот ";
            break;
        case 9:
            Number = "девятьсот ";
            break;
    }
    return Number;
}
std::string Second(int num1, int num2){
    std::string Number;
    if(num1 == 1){
        switch (num2){
            case 0:
                Number = "десять ";
                break;
            case 1:
                Number = "одиннадцать ";
                break;
            case 2:
                Number = "двенадцать ";
                break;
            case 3:
                Number = "тринадцать ";
                break;
            case 4:
                Number = "четырнадцать ";
                break;
            case 5:
                Number = "пятнадцать ";
                break;
            case 6:
                Number = "шестнадцать ";
                break;
            case 7:
                Number = "семнадцать ";
                break;
            case 8:
                Number = "восемнадцать ";
                break;
            case 9:
                Number = "девятнадцать ";
                break;
        }
    }else{
        switch (num1){
            case 0:
                break;
            case 2:
                Number = "двацдать ";
                break;
            case 3:
                Number = "тридцать ";
                break;
            case 4:
                Number = "сорок ";
                break;
            case 5:
                Number = "пятьдесят ";
                break;
            case 6:
                Number = "шестьдесят ";
                break;
            case 7:
                Number = "семьдесят ";
                break;
            case 8:
                Number = "восемьдесят ";
                break;
            case 9:
                Number = "девяносто ";
                break;
    }
    }
    return Number;
}
std::string First(int num){
    std::string Number;
    switch (num){
        case 0:
            break;
        case 1:
            Number = "один ";
            break;
        case 2:
            Number = "два ";
            break;
        case 3:
            Number = "три ";
            break;
        case 4:
            Number = "четыре ";
            break;
        case 5:
            Number = "пять ";
            break;
        case 6:
            Number = "шесть ";
            break;
        case 7:
            Number = "семь ";
            break;
        case 8:
            Number = "восемь ";
            break;
        case 9:
            Number = "девять ";
            break;
    }
    return Number;
}
std::string NaturalLanguage(int Number){
    bool flag1 = true;
    bool flag2 = false;
    std::vector<int> Num;
    std::string answer;
    int k = 0;
    for(; Number / 1 != 0; ++k){
        Num.push_back(Number % 10);
        Number/=10;
    }
    switch(k){
        case 9:
            answer += Thirst(Num[8]);
            //answer +=" ";
            --k;
        case 8:
            answer += Second(Num[7],Num[6]);
           // answer +=" ";
            if(Num[7] == 1)
                flag1 = false;
            --k;
        case 7:
            if(flag1){
                answer += First(Num[6]);
               // answer +=" ";
                switch (Num[6]){
                    case 1:
                        answer += "миллион ";
                        break;
                    case 2:
                        answer += "миллиона ";
                        break;
                    case 3:
                        answer += "миллиона ";
                        break;
                    case 4:
                        answer += "миллиона ";
                        break;
                    default:
                        answer += "миллионов ";
                        break;
                }
            }else
                answer += "миллионов ";
           // answer +=" ";
            --k;
            flag1 = true;
        case 6:
            answer += Thirst(Num[5]);
            if (Num[5] != 0)
                flag2 = true;
           // answer +=" ";
            --k;
        case 5:
            answer += Second(Num[4],Num[3]);
            if (Num[4] != 0)
                flag2 = true;
            //answer +=" ";
            if(Num[4] == 1)
                flag1 = false;
            --k;
        case 4:
            if (Num[3] != 0)
                flag2 = true;
            if(flag1){
                answer += First(Num[3]);
                //answer +=" ";
                switch (Num[3]){
                    case 0:
                        if(flag2)
                            answer += "тысяч";
                        break;
                    case 1:
                        answer += "тысяча ";
                        break;
                    case 2:
                        answer += "тысячи ";
                        break;
                    case 3:
                        answer += "тысячи ";
                        break;
                    case 4:
                        answer += "тысячи ";
                        break;
                    default:
                        answer += "тысяч ";
                        break;
                }
            }else
                answer += "тысяч ";
            //answer +=" ";
            --k;
            flag1 = true;
        case 3:
            answer += Thirst(Num[2]);
            //answer +=" ";
            --k;
        case 2:
            answer += Second(Num[1],Num[0]);
           // answer +=" ";
            if(Num[1] == 1)
                flag1 = false;
            --k;
        case 1:
            
            if(flag1)
                answer += First(Num[0]);
            --k;
    }

    return answer;

}


int main(int argc, const char * argv[]) {
    int Number;
    do{
        std::cout << "Введите число(1-999999999), которое нужно представить на русском языке: ";
        std::cin >> Number;
        }
    while(Number >1000000000 || Number <= 0);
   
    
    std::cout << std::endl << Number << ": " << NaturalLanguage(Number);
    std::cout << std::endl;
    return 0;
}
