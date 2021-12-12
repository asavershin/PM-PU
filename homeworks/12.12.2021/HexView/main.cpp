#include <iostream>
#include <string>
#include <fstream>
typedef unsigned char uchar;
std::string LineNumber(int k){
    unsigned int a = k;
    unsigned int tmp = a;
    unsigned int m = 0;
    std::string result = "";
    while (tmp) {
        ++m;
        tmp >>= 4; // tmp /= 16;
    }
    m = m>0 ? m-1 : 0;
    m = 1 << (4*m);

    tmp = a;
    while (m) {
        int digit = tmp / m;
        if (digit<10)
            result += std::to_string(digit);
        else
            result += char('A' + digit - 10);
        tmp %= m;
        m >>= 4;  //  m /= 16;
    }
    
    return result;
    
}

std::string Nulls(std::string result){
    for(int count = int(result.length()); count < 10; ++count)
        result = "0"+result;
    
    return result;
}


std::string SymbolCode(uchar Byte){
    int code_10 = Byte;
    std::string result_16 = LineNumber(code_10);
    if(result_16.length() < 2)
        result_16 = "0" + result_16;
    return result_16;
    
}
void Hex(std::ifstream & ReadFile, std::ofstream & WriteFile){
    uchar symbol;
    std::string string_16 = "";
    int k1,k2;
    
    
    
    for(int count = 0; ReadFile.peek() != EOF; ++count){
        WriteFile << Nulls(LineNumber(count)) << "0: ";
        for(k1 = 0; k1 < 8 and ReadFile.peek() != EOF; ++k1){
            symbol = ReadFile.get();
            if(symbol < 32)
                string_16 += ".";
            else
                string_16 += symbol;
            WriteFile << SymbolCode(symbol) << " ";
        }
        if(ReadFile.peek() != EOF) {
            WriteFile << "| ";
        }
        
        for(k2 = 0; k2 < 8 and ReadFile.peek() != EOF; ++k2){
            symbol = ReadFile.get();
            if(symbol < 32)
                string_16 += ".";
            else
                string_16 += symbol;
            WriteFile << SymbolCode(symbol) << " ";
        }
        
        if(ReadFile.peek() != EOF){
            WriteFile << string_16 << std::endl;
            string_16 = "";
        }
    }
    
    if(k1 < 8){
        for(;k1 < 8; ++k1)
            WriteFile << "   ";
        WriteFile << "| ";
    }
    
    if(k2 < 8)
        for(;k2 < 8; ++k2)
            WriteFile << "   ";
    WriteFile << string_16;
    ReadFile.close();
    WriteFile.close();
    std::cout << "END!" << std::endl;
    
}
int main(int argc, const char * argv[]) {
    
    std::string FileInput_str, FileOutput_str;
    if(argc < 2){
        std::cout << "Read file: ";
        std::cin >> FileInput_str;
    }else
        FileInput_str = argv[1];
    
    if(argc < 3){
        std::cout << "Write file: ";
        std::cin >> FileOutput_str;
    }else
        FileOutput_str = argv[2];
    try{
        std::ifstream FileInput(FileInput_str);
        std::ofstream FileOutput(FileOutput_str);
        if(!FileInput)
            throw 1;
        if(!FileOutput)
            throw 2;
        Hex(FileInput, FileOutput);
    }
    catch(int a){
        if(a == 1)
            std::cout << "Error: can not open input file" << std::endl;
        else if(a == 2)
            std::cout << "Error: can not open output file" << std::endl;
        else
            std::cout << "Unknown error" << std::endl;
    }
    catch(...){
        std::cout << "Unknown error" << std::endl;
    }
    return 0;
}
