
#include <stdexcept>
using namespace std;

namespace MySTL {

    template <typename T>
    forward_list<T>::forward_list() : head(nullptr), tail(nullptr) {}

    template <typename T>
    forward_list<T>::~forward_list() {
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
    forward_list<T>::forward_list(const forward_list& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    template <typename T>
    forward_list<T>& forward_list<T>::operator=(const forward_list& other) {
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
    bool forward_list<T>::isEmpty() {
        return head == nullptr;
    }

    template <typename T>
    void forward_list<T>::push_front(T val) {
        Node* newnode = new Node(val, head);
        head = newnode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    template <typename T>
    void forward_list<T>::push_back(T val) {
        Node* newnode = new Node(val);
        if (isEmpty()) {
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }

    template <typename T>
    void forward_list<T>::push_at(size_t position, T val) {
        if (position == 0) {
            push_front(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* current = head;
        for (size_t i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            delete newnode;
            throw out_of_range("Position out of range");
        }
        newnode->next = current->next;
        current->next = newnode;
        if (newnode->next == nullptr) {
            tail = newnode;
        }
    }

    template <typename T>
    void forward_list<T>::pop_front() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    template <typename T>
    void forward_list<T>::pop_back() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    template <typename T>
    void forward_list<T>::pop_at(std::size_t position) {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }
        if (position == 0) {
            pop_front();
            return;
        }
        Node* current = head;
        for (size_t i = 0; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }
        if (current->next == nullptr) {
            throw out_of_range("Position out of range");
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (current->next == nullptr) {
            tail = current;
        }
        delete temp;
    }

    template <typename T>
    void forward_list<T>::remove(T val) {
        if (isEmpty()) {
            throw out_of_range("List is empty");
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
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            prev->next = current->next;
            if (prev->next == nullptr) {
                tail = prev;
            }
        }
        delete current;
    }

    template <typename T>
    void forward_list<T>::clear() {
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
    T forward_list<T>::front() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    template <typename T>
    T forward_list<T>::back() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }
        return tail->data;
    }

    template <typename T>
    void forward_list<T>::display() const {
        Node* current = head;
        cout << "[ ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "]" << endl;
    }

    template<typename T>
    void forward_list<T>::reverse(){
        Node* current=head;
        Node* forward=nullptr;
        Node* backward=nullptr;
        tail=head;
        while(current!=nullptr){
            forward=current->next;
            current->next=backward;
            backward=current;
            current=forward;
        }
        head=backward;        
    }

    template<typename T>
    bool forward_list<T>::find(T val){
        Node* current=head;
        while(current!=nullptr){
            if(current->data==val){
                return true;
            }
            current=current->next;
        }
        throw out_of_range("Value not found");
    }


}
