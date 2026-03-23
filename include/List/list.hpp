#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <stdexcept>

namespace MySTL {

    template <typename T>
    class list {
    private:
        std::size_t size_; 
        struct Node {
            T data;
            Node* next;
            Node* prev;
            Node(const T& val, Node* next = nullptr, Node* prev = nullptr) : data(val), next(next), prev(prev) {}
        };
        
        Node* head;
        Node* tail;

    public:
        list();
        list(const T& val);
        list(std::size_t n, const T& val);
        ~list();
        list(const list& other);
        list& operator=(const list& other);

        bool isEmpty();
        std::size_t size() const;

        void push_front(T val);
        void push_back(T val);
        void insert(std::size_t position, T val);

        void pop_front();
        void pop_back();
        void erase(std::size_t position);

        void clear();
        void remove(T val);

        T& front();
        T& back();

        void display() const;
    };
}

#include "../src/List/list.tpp"

#endif
