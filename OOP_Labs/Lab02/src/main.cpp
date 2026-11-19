#include <iostream>

#include "lab_02/string.hpp"

int main() {
    String s1("Hello");
    s1.append(", World!");
    std::cout << "String: ";
    s1.print(std::cout);
    std::cout << '\n';

    String str("ababab");
    String sub("aba");
    std::cout << "Target: " << str.c_str() << '\n';
    std::cout << "Substring: " << sub.c_str() << '\n';
    std::cout << "Occurrences: " << str.count_occurrences(sub) << '\n';

    return 0;
}
