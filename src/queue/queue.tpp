#include <stdexcept>

namespace MySTL {

    template <typename T>
    queue<T>::queue() : data_(nullptr), capacity_(0), size_(0), front_index_(0), rear_index_(0) {}

    template <typename T>
    queue<T>::~queue() {
        delete[] data_;
    }

    template <typename T>
    queue<T>::queue(const queue& other) 
        : capacity_(other.capacity_), size_(other.size_), front_index_(other.front_index_), rear_index_(other.rear_index_) {
        data_ = (capacity_ > 0) ? new T[capacity_] : nullptr;
        
        for (std::size_t i = 0; i < size_; ++i) {
            std::size_t index = (front_index_ + i) % capacity_;
            data_[index] = other.data_[index];
        }
    }

    template <typename T>
    queue<T>& queue<T>::operator=(const queue& other) {
        if (this != &other) {
            delete[] data_;
            
            capacity_ = other.capacity_;
            size_ = other.size_;
            front_index_ = other.front_index_;
            rear_index_ = other.rear_index_;
            
            data_ = (capacity_ > 0) ? new T[capacity_] : nullptr;
            for (std::size_t i = 0; i < size_; ++i) {
                std::size_t index = (front_index_ + i) % capacity_;
                data_[index] = other.data_[index];
            }
        }
        return *this;
    }

    template <typename T>
    void queue<T>::reallocate(std::size_t new_capacity) {
        T* new_data = new T[new_capacity];
        
        try {

            for (std::size_t i = 0; i < size_; ++i) {
                std::size_t old_index = (front_index_ + i) % capacity_;
                new_data[i] = std::move(data_[old_index]);
            }
        } catch (...) {
            delete[] new_data;
            throw;
        }
        
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
        
        front_index_ = 0;
        rear_index_ = size_; 
    }

    template <typename T>
    void queue<T>::push(const T& value) {
        if (size_ == capacity_) {
            std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(new_capacity);
        }
        
        data_[rear_index_] = value;
        rear_index_ = (rear_index_ + 1) % capacity_;
        ++size_;
    }

    template <typename T>
    void queue<T>::pop() {
        if (isEmpty()) {
            throw std::out_of_range("Queue underflow: Cannot pop from an empty queue");
        }
        front_index_ = (front_index_ + 1) % capacity_;
        --size_;
    }

    template <typename T>
    T& queue<T>::front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data_[front_index_];
    }

    template <typename T>
    const T& queue<T>::front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data_[front_index_];
    }

    template <typename T>
    bool queue<T>::isEmpty() const {
        return size_ == 0;
    }

    template <typename T>
    std::size_t queue<T>::size() const {
        return size_;
    }
}
