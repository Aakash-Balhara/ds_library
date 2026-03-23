#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

namespace MySTL {
    template <typename T>
    class queue {
    private:
        T* data_;
        std::size_t capacity_;
        std::size_t size_;
        std::size_t front_index_;
        std::size_t rear_index_;

        void reallocate(std::size_t new_capacity);

    public:
        queue();
        ~queue();
        queue(const queue& other);
        queue& operator=(const queue& other);

        void push(const T& value);
        void pop();
        T& front();
        const T& front() const;
        bool isEmpty() const;
        std::size_t size() const;
    };
}

#include "../../src/queue/queue.tpp"

#endif