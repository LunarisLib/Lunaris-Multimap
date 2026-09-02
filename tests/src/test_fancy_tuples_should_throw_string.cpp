#include <string>
#include <iostream>
#include <concepts>
#include <type_traits>

#include <Lunaris/multimap.h>

template<typename T, typename U>
concept CanAssign = requires(T& t, U&& u) {
    t = std::forward<U>(u);
};

template<typename T, typename U>
concept CanCompare = requires(const T& t, const U& u) {
    { t == u } -> std::convertible_to<bool>;
};


using namespace Lunaris::MultiMap;

int main() {
    using TargetTuple = fancy_tuple<int, std::string>;

    // Valid checks
    static_assert(CanAssign<TargetTuple, int>);
    static_assert(CanAssign<TargetTuple, std::string>);
    static_assert(CanCompare<TargetTuple, int>);
    static_assert(CanCompare<TargetTuple, std::string>);

    // Invalid checks (Must fail)
    static_assert(!CanAssign<TargetTuple, const char*>);
    static_assert(!CanAssign<TargetTuple, double>);
    static_assert(!CanCompare<TargetTuple, const char*>);
    static_assert(!CanCompare<TargetTuple, double>);

    TargetTuple yay{1, std::string("hello")};

    yay = 10;
    yay = std::string("This is working");

    if (!(yay == 10 && yay == std::string("This is working"))) {
        std::cout << "Runtime tests failed!\n";
        return 1;
    }

    return 0;
}