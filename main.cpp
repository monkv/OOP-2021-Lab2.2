#include <iostream>
#include <vector>
#include "binary.h"

std::vector<std::string> MENU_MSG = {"0. Quit", "1. Default Initialization", "2. Initialization by long ", "3.Initialization by string",
                                     "4. Initialization of a number of numbers (lol)", "5. Get two’s complement", "6. Subtraction",
                                     "7. Prefix increment ", "8. Postf decrement", "9. Get a sign of the number"};
int main() {
    int c = 0, n;
    binary_num NUM;
    binary_num summand;
    binary_num* mass;
    std::string input;
    long a;
    char* buf = nullptr;
    do {
        for (int i = 0; i < MENU_MSG.size(); i++)
            std::cout << MENU_MSG[i] << "\n";
        std::cout << "\nChoose an option: ";
        std::cin >> c;
        switch (c) {
            case 0:
                break;
            case 1:
                NUM = binary_num();
                break;
            case 2:
                std::cout << "\nEnter a decimal number (type long): ";
                std::cin >> a;
                try {
                    NUM = binary_num(a);
                }
                catch (std::invalid_argument &msg){
                    std::cerr << msg.what() << std::endl;
                }
                break;
            case 3:
                std::cout << "\nEnter a decimal number (string): ";
                std::cin >> input;
                try{
                    NUM = binary_num(input);
                }
                catch (std::invalid_argument &msg){
                    std::cerr << msg.what() << std::endl;
                }
                break;
            case 4:
                std::cout << "\nEnter a number of binary numbers: ";
                std::cin >> n;
                 mass = new binary_num[n];
                for (int i = 0; i < n; i++){
                    std::cin >> mass[i];
                }
                for (int i = 0; i < n; i++){
                    std::cout << mass[i];
                }
                break;
            case 5:
                std::cout << "\nThe twos-component : ";
                std::cout << NUM.get_2compl() << std::endl;
                break;
            case 6:
                if (NUM.get_sign()){
                    std::cout << "\nEnter a positive  number: ";
                }
                else{
                    std::cout << "\nEnter a negative  number: ";
                }
                std::cin >> summand;
                std::cout << "result of subtraction" << subtraction(summand, NUM) << std::endl;
                break;
            case 7:{
                std::cout << "result of pref. increment" << ++NUM << std::endl;
                break;
            }
            case 8:{
                std::cout << "result of post. decrement:" << NUM-- << std::endl;
                break;
            }
            case 9:{
                if (NUM.get_sign())
                    std::cout << "\nthe number is negative" << std::endl;
                else
                    std::cout << "\nthe number is positive" << std::endl;
                break;
            }
        }
    } while (c);
    return 0;
}