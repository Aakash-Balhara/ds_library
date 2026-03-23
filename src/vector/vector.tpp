#include <stdexcept>

namespace MySTL
{

    template <typename T>
    Vector<T>::Vector() : size_(0), capacity_(0), data_(nullptr) {}

    template <typename T>
    Vector<T>::~Vector()
    {
        delete[] data_;
    }

    template <typename T>
    Vector<T>::Vector(const Vector &other) : size_(other.size_), capacity_(other.capacity_)
    {
        data_ = (capacity_ > 0) ? new T[capacity_] : nullptr;
        
        try
        {
            for (std::size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }
        catch (...)
        {
            delete[] data_;
            throw;
        }
    }

    template <typename T>
    Vector<T> &Vector<T>::operator=(const Vector &other)
    {
        if (this != &other)
        {
            Vector<T> temp(other); // Use copy-and-swap idiom
            std::swap(size_, temp.size_);
            std::swap(capacity_, temp.capacity_);
            std::swap(data_, temp.data_);
        }
        return *this;
    }

    template <typename T>
    T &Vector<T>::operator[](std::size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    template <typename T>
    const T &Vector<T>::operator[](std::size_t index) const
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    template <typename T>
    void Vector<T>::push_back(const T &value)
    {
        if (size_ == capacity_)
        {
            std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(new_capacity);
        }
        data_[size_] = value;
        ++size_;
    }

    template <typename T>
    void Vector<T>::pop_back()
    {
        if (size_ > 0)
        {
            --size_;
        }
    }

    template <typename T>
    std::size_t Vector<T>::size() const
    {
        return size_;
    }

    template <typename T>
    std::size_t Vector<T>::capacity() const
    {
        return capacity_;
    }

    template <typename T>
    void Vector<T>::reallocate(std::size_t new_capacity)
    {
        T *new_data = new T[new_capacity];

        try
        {
            for (std::size_t i = 0; i < size_; ++i)
            {
                new_data[i] = std::move(data_[i]);
            }
        }
        catch (...)
        {
            delete[] new_data;
            throw;
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
}
