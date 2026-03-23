#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

namespace MySTL{

template <typename T>
class Vector {

    private:
    std::size_t size_;
    std::size_t capacity_;
    T* data_;

    void reallocate(std::size_t new_capacity);

public:
    
    Vector();

    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    void push_back(const T& value);
    void pop_back();

    std::size_t size() const;
    std::size_t capacity() const;

};
}

#include "../../src/vector/vector.tpp"

#endif
