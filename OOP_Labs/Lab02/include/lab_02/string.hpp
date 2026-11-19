#pragma once

#include <cstddef>
#include <iostream>

class String {
private:
    char* data_{nullptr};
    std::size_t size_{0};
    std::size_t capacity_{1};

public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(String other) noexcept;
    ~String();

    void swap(String& other) noexcept;

    std::size_t size() const;
    std::size_t capacity() const;
    const char* c_str() const;

    void push_back(char c);
    void append(const char* str);
    void append(const String& other);
    void print(std::ostream& os) const;
    std::size_t find(const char* substr) const;

    std::size_t count_occurrences(const String& substr) const;
    std::size_t count_occurences(const String& substr) const {
        return count_occurrences(substr);
    }
};
