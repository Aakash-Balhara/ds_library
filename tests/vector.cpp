#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../include/vector/vector.hpp"

using namespace MySTL;

void test_vector() {

    Vector<int> v;
    assert(v.size() == 0);
    assert(v.capacity() == 0);

    v.push_back(10);
    assert(v.size() == 1);
    assert(v.capacity() == 1);
    assert(v[0] == 10);

    v.push_back(20);
    assert(v.size() == 2);
    assert(v.capacity() == 2);
    assert(v[1] == 20);

    v.push_back(30);
    assert(v.size() == 3);
    assert(v.capacity() == 4);
    assert(v[2] == 30);

    bool caught = false;
    try {
        int x = v[5];
    } catch (const std::out_of_range& e) {
        caught = true;
    }
    assert(caught);

    v.pop_back();
    assert(v.size() == 2);
    assert(v.capacity() == 4);

    Vector<int> v2(v);
    assert(v2.size() == 2);
    assert(v2.capacity() == 4);
    assert(v2[0] == 10);
    assert(v2[1] == 20);

    Vector<int> v3;
    v3.push_back(99);
    v3 = v;
    assert(v3.size() == 2);
    assert(v3.capacity() == 4);
    assert(v3[0] == 10);
    assert(v3[1] == 20);
    
    v3 = v3;
    assert(v3.size() == 2);

    Vector<std::string> vs;
    vs.push_back("Hello");
    vs.push_back("World");
    assert(vs.size() == 2);
    assert(vs[0] == "Hello");
    assert(vs[1] == "World");

    std::cout << "All Vector tests passed successfully!\n";
}