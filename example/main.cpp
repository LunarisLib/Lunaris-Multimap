#include <iostream>
#include <string>

#include <Lunaris/multimap.h>

using namespace Lunaris::MultiMap;

int main() {
    
    mksv_map<int, std::string, unsigned> mksv_test = {
        { {std::string("one"), 1u}, 1 },
        { {std::string("two"), 2u}, 2 }
    };

    std::cout << "Value of 'one' is " << mksv_test[std::string("one")] << std::endl;
    std::cout << "Value of '1u' is " << mksv_test[1u] << std::endl;

    mksv_test.set(fancy_tuple<std::string, unsigned int>{std::string("three"), 3u}, 3);

    std::cout << "Value of 'three' is " << mksv_test[std::string("three")] << std::endl;
    std::cout << "Value of '3u' is " << mksv_test[3u] << std::endl;


    skmv_map<int, std::string, unsigned> skmv_test = {
        {1, {std::string("one"), 1u} },
        {2, {std::string("two"), 2u} }
    };

    const auto& test2 = skmv_test[1];
    const unsigned test2_u = test2;
    const std::string test2_s = test2;

    std::cout << "Value of 1 is '" << test2_u << "' and also '" << test2_s << "'" << std::endl;

    const auto& test3 = skmv_test[2];
    const unsigned& test3_u = test3;
    const std::string& test3_s = test3;

    skmv_test[2] = 2u;
    skmv_test[2] = std::string("TWO");

    std::cout << "Value of 2 is '" << test3_u << "' and also '" << test3_s << "'" << std::endl;



    /*fancy_tuple<int, char, long, double, std::string> yay{
        1, 'a', 2L, 3.14, std::string("hello")
    };

    if (yay == 1) std::cout << "INT OK\n";
    if (yay == 'a') std::cout << "CHAR OK\n";
    if (yay == 2L) std::cout << "LONG OK\n";
    if (yay == 3.14) std::cout << "DOUBLE OK\n";
    if (yay == std::string("hello")) std::cout << "STR OK\n";

    int yayint = yay;
    if (yayint == 1) std::cout << "INT2 OK\n";
    const int& yayref = yay;
    if (yayref == 1) std::cout << "INT3 OK\n";


    yay = 10;
    yay = 'z';
    yay = 25L;
    yay = 42.69;
    yay = std::string("This is strange");

    yayint = yay;
    if (yayint == 10) std::cout << "INT2 OK\n";
    if (yayref == 1) std::cout << "INT3 OK\n";

    if (yay == 10) std::cout << "INT OK\n";
    if (yay == 'z') std::cout << "CHAR OK\n";
    if (yay == 25L) std::cout << "LONG OK\n";
    if (yay == 42.69) std::cout << "DOUBLE OK\n";
    if (yay == std::string("This is strange")) std::cout << "STR OK\n";*/

    return 0;
}