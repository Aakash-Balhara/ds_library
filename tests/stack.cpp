#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../include/stack/stack.hpp"

using namespace MySTL;

void test_stack() {
    std::cout << "Testing stack...\n";
    stack<int> s;
    assert(s.isEmpty());
    assert(s.size() == 0);

    s.push(10);
    s.push(20);
    s.push(30);
    assert(s.size() == 3);
    assert(s.top() == 30);

    s.pop();
    assert(s.size() == 2);
    assert(s.top() == 20);

    s.pop();
    s.pop();
    assert(s.isEmpty());
    assert(s.size() == 0);

    bool caught = false;
    try {
        s.pop();
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    std::cout << "All Stack tests passed successfully!\n";
}