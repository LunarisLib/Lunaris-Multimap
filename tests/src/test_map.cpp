#include <iostream>
#include <string>

#include <Lunaris/multimap.h>

using namespace Lunaris::MultiMap;

int main() {
    mksv_map<int, std::string, unsigned> mksv_test = {
        { {std::string("one"), 1u}, 1 },
        { {std::string("two"), 2u}, 2 }
    };

    if (mksv_test[std::string("one")] != 1) return 1;
    if (mksv_test[1u] != 1) return 1;

    std::cout << "Value of 'one' is " << mksv_test[std::string("one")] << std::endl;
    std::cout << "Value of '1u' is " << mksv_test[1u] << std::endl;

    mksv_test.set(fancy_tuple<std::string, unsigned int>{std::string("three"), 3u}, 3);

    if (mksv_test[std::string("three")] != 3) return 1;
    if (mksv_test[3u] != 3) return 1;

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

    if (skmv_test[1] != 1u || skmv_test[1] != std::string("one")) return 2;

    const auto& test3 = skmv_test[2];
    const unsigned& test3_u = test3;
    const std::string& test3_s = test3;

    skmv_test[2] = 2u;
    skmv_test[2] = std::string("TWO");

    std::cout << "Value of 2 is '" << test3_u << "' and also '" << test3_s << "'" << std::endl;

    if (skmv_test[2] != 2u || skmv_test[2] != std::string("TWO")) return 2;

    std::cout << "All tests passed!\n";

    return 0;
}