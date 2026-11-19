#include "lab_02/string.hpp"

#include <cstring>
#include <utility>

String::String() : size_(0), capacity_(1) {
    data_ = new char[capacity_ + 1];
    data_[0] = '\0';
}

String::String(const char* str) {
    if (!str) {
        size_ = 0;
        capacity_ = 1;
        data_ = new char[capacity_ + 1];
        data_[0] = '\0';
    } else {
        size_ = std::strlen(str);
        capacity_ = size_ > 0 ? size_ : 1;
        data_ = new char[capacity_ + 1];
        std::strcpy(data_, str);
    }
}

String::~String() {
    delete[] data_;
}

String::String(const String& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new char[capacity_ + 1];
    if (other.data_) {
        std::strcpy(data_, other.data_);
    } else {
        data_[0] = '\0';
    }
}

String::String(String&& other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
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

std::size_t String::size() const {
    return size_;
}

std::size_t String::capacity() const {
    return capacity_;
}

const char* String::c_str() const {
    return data_ ? data_ : "";
}

void String::push_back(char c) {
    if (size_ == capacity_) {
        std::size_t new_cap = capacity_ * 2;
        char* new_data = new char[new_cap + 1];
        std::strcpy(new_data, data_);
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }
    data_[size_] = c;
    ++size_;
    data_[size_] = '\0';
}

void String::append(const char* str) {
    if (!str) {
        return;
    }
    std::size_t add_len = std::strlen(str);
    if (add_len == 0) {
        return;
    }

    std::size_t needed = size_ + add_len;
    if (needed > capacity_) {
        std::size_t new_cap = capacity_;
        while (new_cap < needed) {
            new_cap *= 2;
        }
        char* new_data = new char[new_cap + 1];
        if (data_) {
            std::strcpy(new_data, data_);
            delete[] data_;
        }
        data_ = new_data;
        capacity_ = new_cap;
    }
    std::strcpy(data_ + size_, str);
    size_ = needed;
}

void String::append(const String& other) {
    append(other.c_str());
}

void String::print(std::ostream& os) const {
    os << (data_ ? data_ : "");
}

std::size_t String::find(const char* substr) const {
    if (!substr || !data_) {
        return static_cast<std::size_t>(-1);
    }
    const char* pos = std::strstr(data_, substr);
    if (!pos) {
        return static_cast<std::size_t>(-1);
    }
    return static_cast<std::size_t>(pos - data_);
}

std::size_t String::count_occurrences(const String& substr) const {
    if (substr.size_ == 0 || substr.size_ > size_) {
        return 0;
    }

    std::size_t count = 0;
    std::size_t i = 0;

    while (i + substr.size_ <= size_) {
        bool match = true;
        for (std::size_t j = 0; j < substr.size_; ++j) {
            if (data_[i + j] != substr.data_[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            ++count;
            i += substr.size_;
        } else {
            ++i;
        }
    }

    return count;
}
