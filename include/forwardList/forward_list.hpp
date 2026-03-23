#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <stdexcept>
#include <cstddef>

namespace MySTL {

    template <typename T>
    class forward_list {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& val, Node* next = nullptr) : data(val), next(next) {}
        };
        
        Node* head;
        Node* tail;

    public:
        forward_list();
        ~forward_list();
        forward_list(const forward_list& other);
        forward_list& operator=(const forward_list& other);

        bool isEmpty();

        void push_front(T val);
        void push_back(T val);
        void push_at(std::size_t position, T val);

        void pop_front();
        void pop_back();
        void pop_at(std::size_t position);

        void remove(T val);
        void clear();

        T front();
        T back();

        void reverse();
        bool find(T val);

        void display() const;
        
    };

}

#include "../../src/forwardList/forward_list.tpp"

#endif
