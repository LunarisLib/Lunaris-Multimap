#include <iostream>
#include <string>

#include <Lunaris/multimap.h>

using namespace Lunaris::MultiMap;

int main() {
    fancy_tuple<int, char, long, double, std::string> yay{
        1, 'a', 2L, 3.14, std::string("hello")
    };

    if (yay == 1) std::cout << "INT OK\n";
    else return 1;
    if (yay == 'a') std::cout << "CHAR OK\n";
    else return 2;
    if (yay == 2L) std::cout << "LONG OK\n";
    else return 3;
    if (yay == 3.14) std::cout << "DOUBLE OK\n";
    else return 4;
    if (yay == std::string("hello")) std::cout << "STR OK\n";
    else return 5;

    int yayint = yay;
    if (yayint == 1) std::cout << "INT2 OK\n";
    else return -1;
    const int& yayref = yay;
    if (yayref == 1) std::cout << "INT3 OK\n";
    else return -2;

    yay = 10;
    yay = 'z';
    yay = 25L;
    yay = 42.69;
    yay = std::string("This is strange");

    if (yay == 10) std::cout << "INT OK\n";
    else return 6;
    
    yayint = yay;
    if (yayint == 10) std::cout << "INT2 OK\n";
    else return -3;
    if (yayref == 10) std::cout << "INT3 OK\n";
    else return -4;

    if (yay == 'z') std::cout << "CHAR OK\n";
    else return 7;
    if (yay == 25L) std::cout << "LONG OK\n";
    else return 8;
    if (yay == 42.69) std::cout << "DOUBLE OK\n";
    else return 9;
    if (yay == std::string("This is strange")) std::cout << "STR OK\n";
    else return 10;

    std::cout << "All tests passed!\n";

    return 0;
}