#include <iostream>
#include "lab_02/string.hpp"

int main(){
    String str("ababab");
    String sub("aba");

    std::cout<<"String: "<<str.c_str()<<'\n';
    std::cout<<"Substring: "<<sub.c_str()<<'\n';
    std::cout<<"Count: "<<str.count_occurences(sub)<<'\n';
    return 0;
}