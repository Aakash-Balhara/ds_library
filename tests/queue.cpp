#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../include/queue/queue.hpp"

using namespace MySTL;

void test_queue() {
    std::cout << "Testing queue...\n";
    queue<int> q;
    assert(q.isEmpty());
    assert(q.size() == 0);

    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.size() == 3);
    assert(q.front() == 1);

    q.pop();
    assert(q.size() == 2);
    assert(q.front() == 2);

    q.push(4);
    q.push(5);
    
    queue<int> q2(q);
    assert(q2.size() == 4);
    assert(q2.front() == 2);

    queue<int> q3;
    q3 = q;
    assert(q3.size() == 4);
    assert(q3.front() == 2);

    while (!q.isEmpty()) {
        q.pop();
    }
    assert(q.size() == 0);

    bool caught = false;
    try {
        q.front();
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    std::cout << "All Queue tests passed successfully!\n";
}