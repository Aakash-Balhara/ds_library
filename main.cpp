#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>

// Forward declarations of your test functions
void test_vector();
void test_forwardList();
void test_stack();
void test_queue();
void test_list();

int main() {
    std::cout << "--- Running All Tests ---\n";

    std::cout << "\n--- Running Vector Tests ---\n";
    test_vector();
    std::cout << "\n--- Running ForwardList Tests ---\n";
    test_forwardList();
    std::cout << "\n--- Running Stack Tests ---\n";
    test_stack();
    std::cout << "\n--- Running Queue Tests ---\n";
    test_queue();
    std::cout << "\n--- Running List Tests ---\n";
    test_list();


    std::cout << "\n--- All Tests Completed Successfully! ---\n";
    return 0;
}
