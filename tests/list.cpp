#include <cassert>
#include <stdexcept>
#include "../include/list/list.hpp"

using namespace MySTL;

void test_list() {
    std::cout << "Testing list (Doubly Linked List)...\n";
    
    list<int> l;
    assert(l.isEmpty());
    assert(l.size() == 0);

    l.push_back(10);
    l.push_back(20);
    l.push_front(5);
    assert(l.size() == 3);
    assert(l.front() == 5);
    assert(l.back() == 20);

    l.insert(1, 15);
    assert(l.size() == 4);
    
    l.pop_front();
    assert(l.front() == 15);
    l.pop_back();
    assert(l.back() == 10);
    assert(l.size() == 2);

    l.push_back(30);
    l.erase(1);
    assert(l.size() == 2);
    assert(l.front() == 15);
    assert(l.back() == 30);

    l.remove(15);
    assert(l.size() == 1);
    assert(l.front() == 30);

    l.clear();
    assert(l.isEmpty());
    assert(l.size() == 0);

    bool caught = false;
    try {
        l.pop_front();
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    l.push_back(100);
    l.push_back(200);
    
    list<int> l2(l);
    assert(l2.size() == 2);
    assert(l2.front() == 100);
    assert(l2.back() == 200);

    list<int> l3;
    l3 = l;
    assert(l3.size() == 2);
    assert(l3.front() == 100);
    assert(l3.back() == 200);

    std::cout << "All List tests passed successfully!\n";
}
