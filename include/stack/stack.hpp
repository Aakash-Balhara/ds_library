#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace MySTL {
    template <typename T>
    class stack {
    private:
        MySTL::Vector<T> container_;

    public:
        stack();
        ~stack();
        void push(const T& value);
        void pop();
        const T& top() const;
        bool isEmpty() const;
        std::size_t size() const;
    };
}

#include "../src/stack/stack.tpp"

#endif