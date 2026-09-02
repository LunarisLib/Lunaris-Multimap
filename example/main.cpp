#include <iostream>
#include <string>

#include <Lunaris/multimap.h>

using namespace Lunaris::MultiMap;

int main() {
    fancy_tuple<int, char, long, double, std::string> yay{
        1, 'a', 2L, 3.14, "hello"
    };

    if (yay == 1) std::cout << "INT OK\n";
    if (yay == 'a') std::cout << "CHAR OK\n";
    if (yay == 2L) std::cout << "LONG OK\n";
    if (yay == 3.14) std::cout << "DOUBLE OK\n";
    if (yay == "hello") std::cout << "DOUBLE OK\n";

    yay = 10;
    yay = 'z';
    yay = 25L;
    yay = 42.69;
    yay = "This is strange";

    if (yay == 10) std::cout << "INT OK\n";
    if (yay == 'z') std::cout << "CHAR OK\n";
    if (yay == 25L) std::cout << "LONG OK\n";
    if (yay == 42.69) std::cout << "DOUBLE OK\n";
    if (yay == "This is strange") std::cout << "DOUBLE OK\n";

    return 0;
}