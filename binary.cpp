#include "binary.h"
#include <iostream>
#include <string>
#include <cmath>

binary_num::~binary_num(){
    delete []bin_num;
}
binary_num::binary_num(char* buf, int length) {
    char* bin_num = new char[length];
    memcpy(bin_num, buf, length);
    int i = length;
    while (buf[i] != 1)
        i--;
    size = i;
}
binary_num::binary_num(long n){
    bool negative = (n < 0);
    if (negative)
        n = -n;
    int i = 0, j = 0;
    while (pow(2, j) <= n){
        j++;
    };
    size = j + 1;
    bin_num = new char[size];
    do{
        bin_num[i] = (char) n % 2;
        n = n / 2;
        i++;
    } while (n > 0);
    if (negative){
        bin_num[size] = 1;
    }
    else bin_num[size] = 0;
    //std::cout << "size= " << size << std::endl;
    for (int k = 0; k <= size; k++){
        std::cout << (int)bin_num[k];
    }
}

binary_num::binary_num(std::string &str){
    long decimal = std::stoi(str);
    *this = binary_num(decimal);
}

binary_num::binary_num(binary_num &obj){
    delete []this->bin_num;
    size = obj.size;
    bin_num = new char[size];
    memcpy(bin_num, obj.bin_num, size);
};


void* add_one(char* buf, int &s){
    int diff = 0, add = 1, i = 0;
    while (buf[i] + add + diff > 1){
        buf[i] = buf[i] + add + diff - 2;
        diff = 1;
        add = 0;
        i++;
    }
    if (i == 0)
        buf[i] = buf[i] + add + diff;
    return buf;
}

char* binary_num::get_twos_complement(char* buffer){
    if (bin_num[size] != 0){
        buffer[size] = 1;
        for (int i = 0; i < 100; i++){
            if (bin_num[i] == 0)
                buffer[i] = 1;
            else
                buffer[i] = 0;
        }
        add_one(buffer, size);
    }
    else{
        memcpy(buffer, bin_num, size);
    }
    return buffer;
}
char* binary_num::get_2compl(){
    char* buffer = new char[size];
    return get_twos_complement(buffer);
}
char* equalization(char* vect, int s_new, int s_old){
    for (int i = s_old; i < s_new; i++){
        vect[i] = 1;
    }
    return vect;
}
binary_num subtraction(binary_num &obj1, binary_num &obj2){
    int diff = 0, len = 0; //доп в десяток
    char* res;
    char* summand1 = new char[obj1.size];
    summand1 = obj1.get_twos_complement(summand1);
    char* summand2 = new char[obj2.size];
    summand2 = obj2.get_twos_complement(summand2);
    if (obj1.size > obj2.size){
        len = obj1.size;
        summand2 = new char[len];
        summand2 = equalization(summand2, obj1.size, obj2.size);
    }else{
        len = obj2.size;
        summand1 = new char[len];
        summand1 = equalization(summand1, obj2.size, obj1.size);
    }
    res = new char[len];
    for (int i = 0; i <= len; i++){
        if (summand1[i] + summand2[i] + diff > 1){
            res[i] = summand1[i] + summand2[i] + diff - 2;
            diff = 1;
        }
        else{
            res[i] = summand1[i] + summand2[i] + diff;
            diff = 0;
        }
    }
    if (res[len] == 1){
        for (int i = 0; i < len; i++){
            if (res[i] == 0)
                res[i] = 1;
            else
                res[i] = 0;
        }
        add_one(res, len);
    }
    binary_num obj_res (res, len);
    return obj_res;
}

char binary_num::get_sign(){
    if (size != 0)
        return bin_num[size];
    else throw std::invalid_argument("the number doesn't exist");
}


binary_num& binary_num::increment(){ //операции увеличения числа на единицу до использования числа;
    int plus = 1;
    binary_num obj (plus);
    *this = subtraction(*this, obj);
    return *this;
}

binary_num binary_num::decrement(){ //операции уменьшения числа после его использования;
    binary_num copy (*this);
    int minus = -1;
    binary_num obj (minus);
    *this = subtraction(*this, obj);
    return copy;
}

std::ostream& operator<< (std::ostream &out, const binary_num &obj){
    std::cout << obj.bin_num[obj.size];
    for (int i = obj.size; i > 0; i--){
        std::cout << obj.bin_num[i];
    }
    return out;
}
std::istream& operator>> (std::istream& in, binary_num &obj) {
    std::string input;
    in >> input;
    obj = binary_num(input);
    return in;
}
binary_num& binary_num::operator= (const binary_num& obj){
    delete []this->bin_num;
    this->size = obj.size;
    bin_num = new char[size];
    memcpy(this->bin_num, obj.bin_num, size);
    return *this;
}

binary_num& binary_num::operator++ (){
    int plus = 1;
    binary_num obj (plus);
    *this = subtraction(*this, obj);
    return *this;
}

const binary_num binary_num::operator-- (int){ //постфиксный декремент
    binary_num copy (*this);
    int minus = -1;
    binary_num obj (minus);
    *this = subtraction(*this, obj);
    return copy;
}

