#pragma once
#include <cstddef>
#include <iostream>

class String{
    private:
        char* data_=nullptr;
        size_t size_=0;
        size_t capacity_=0;

    public:
        String();
        String(const char* str);
        ~String();

        String(const String& other);
        String(String&& other ) noexcept;
        String& operator=(String other);
        void swap(String& other) noexcept;
        
        size_t size() const;
        size_t capacity() const;
        const char* c_str() const;
        size_t count_occurences(const String& substr) const;
};
