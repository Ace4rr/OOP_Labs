#include "lab_02/string.hpp"
#include <cstring>
#include <utility>

String::String(): size_(0), capacity_(1){
    data_=new char [capacity_ +1];
    data_[0]='\0';
}

String::String(const char* str){
    if (!str){
        size_=0;
        capacity_=1;
        data_=new char[capacity_+1];
        data_[0]='\0';
    } else{
        size_=std::strlen(str);
        capacity_=size_>0 ? size_:1;
        data_=new char[capacity_+1];
        std::strcpy(data_,str);
    }
}

String::~String(){
    delete[] data_;
}

String::String(String&& other) noexcept: data_(other.data_),size_(other.size_), capacity_(other.capacity_){
    other.data_=nullptr;
    other.size_=0;
    other.capacity_=0;
}

void String::swap(String& other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

String& String::operator=(String other) noexcept {
    swap(other);
    return *this;
}

std::size_t String::count_occurrences(const String& substr) const {
    if (substr.size_==0 || substr.size_ >size_) {
        return 0;
    }

    std::size_t count=0;
    std::size_t i=0;

    while (i + substr.size_ <= size_) {
        bool match=true;

        for (std::size_t j=0; j < substr.size_; ++j) {
            if (data_[i + j] != substr.data_[j]){
                match=false;
                break;
            }
        }

        if (match){
            ++count;
            i += substr.size_;
        } else {
            ++i;
        }
    }

    return count;
}
