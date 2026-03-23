#include <iostream>
#include <stdexcept>

namespace MySTL {

    template <typename T>
    list<T>::list() : size_(0), head(nullptr), tail(nullptr) {}

    template <typename T>
    list<T>::list(const T& val) : size_(1), head(new Node(val)), tail(head) {}

    template <typename T>
    list<T>::list(std::size_t n, const T& val) {
        if (n == 0) { 
            head = tail = nullptr; 
            size_ = 0; 
            return; 
        }
        head = new Node(val);
        tail = head;
        size_ = 1;
        for (std::size_t i = 1; i < n; i++) {
            tail->next = new Node(val, nullptr, tail);
            tail = tail->next;
            size_++;
        }
        tail->next = nullptr;           
    }

    template <typename T>
    list<T>::~list() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    template <typename T>
    list<T>::list(const list& other) : size_(0), head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    template <typename T>
    list<T>& list<T>::operator=(const list& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    template <typename T>
    bool list<T>::isEmpty() {
        return head == nullptr;
    }

    template <typename T>
    std::size_t list<T>::size() const {
        return size_;
    }

    template <typename T>
    void list<T>::push_front(T val) {
        Node* newnode = new Node(val, head);
        if (isEmpty()) {
            tail = newnode;
        } else {
            head->prev = newnode;
        }
        head = newnode;
        size_++;
    }

    template <typename T>
    void list<T>::push_back(T val) {
        Node* newnode = new Node(val);
        if (isEmpty()) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        size_++;
    }

    template <typename T>
    void list<T>::insert(std::size_t position, T val) {
        if (position == 0) {
            push_front(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* current = head;
        for (std::size_t i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            delete newnode;
            throw std::out_of_range("Position out of range");
        }
        newnode->next = current->next;
        newnode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newnode;
        }
        current->next = newnode; 
        size_++;
    }

    template <typename T>
    void list<T>::pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size_--;
    }

    template <typename T>
    void list<T>::pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size_--;
            return;
        }
        Node* current = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete current;
        size_--;
    }

    template <typename T>
    void list<T>::erase(std::size_t position) {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        if (position == 0) {
            pop_front();
            return;
        }
        Node* current = head;
        for (std::size_t i = 0; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }
        if (current->next == nullptr) {
            throw std::out_of_range("Position out of range");
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = current;
        } else {
            tail = current;
        }
        delete temp;
        size_--;
    }

    template <typename T>
    void list<T>::clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        tail = nullptr;
        size_ = 0;
    }

    template <typename T>
    void list<T>::remove(T val) {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            return;
        }
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = prev;
        } else {
            tail = prev;
        }
        delete current;
        size_--;
    }

    template <typename T>
    T& list<T>::front() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    template <typename T>
    T& list<T>::back() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    template <typename T>
    void list<T>::display() const {
        Node* current = head;
        std::cout << "[ ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
}
