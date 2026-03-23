#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../include/forwardList/forward_list.hpp"

using namespace MySTL;

void test_forwardList() {
    std::cout << "Testing forward_list...\n";
    forward_list<int> list;
    assert(list.isEmpty());

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    assert(list.front() == 10);
    assert(list.back() == 30);

    list.push_front(5);
    assert(list.front() == 5);

    list.push_at(2, 15);
    assert(list.find(15) == true);
    
    list.pop_front();
    assert(list.front() == 10);

    list.pop_back();
    assert(list.back() == 20);

    list.pop_at(1);
    assert(list.front() == 10);
    assert(list.back() == 20);

    list.reverse();
    assert(list.front() == 20);
    assert(list.back() == 10);

    list.clear();
    assert(list.isEmpty());

    std::cout << "All forward_list tests passed successfully!\n";
}