#include <stdexcept>

namespace MySTL {

    template <typename T>
    stack<T>::stack() {}

    template <typename T>
    stack<T>::~stack() {}

    template <typename T>
    void stack<T>::push(const T& value) {
        container_.push_back(value);
    }

    template <typename T>
    void stack<T>::pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow: Cannot pop from an empty stack");
        }
        container_.pop_back();
    }

    template <typename T>
    const T& stack<T>::top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return container_[container_.size() - 1];
    }

    template <typename T>
    bool stack<T>::isEmpty() const {
        return container_.size() == 0;
    }

    template <typename T>
    std::size_t stack<T>::size() const {
        return container_.size();
    }
}
