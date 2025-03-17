//https://app.asana.com/1/656176460444/project/1208315729461187/task/1209655350170895
#include <iostream>
#include <vector>
#include "Task-1-1.h"

// DO NOT TOUCH

struct mystring {
    std::string s;

    mystring(const std::string& _s) : s(_s) {
        std::cout << "[string created]" << std::endl;
    }

    mystring(const mystring& other) : s(other.s) {
        std::cout << "[string copied]" << std::endl;
    }

    mystring(mystring&& other) : s(std::move(other.s)) {
        std::cout << "[string moved]" << std::endl;
    }
};

// AFTER THIS POINT YOU CAN EDIT

void print(std::vector<mystring> myStringVector) {
    for (mystring x : myStringVector) {
        std::cout << x.s << " ";
    }
    std::cout << std::endl;
}

void Run_1_Task() {
    std::vector<mystring> v;

    mystring s("hello");
    v.push_back(s);

    mystring s2("world");
    v.push_back(s2);

    mystring s3("!");
    v.push_back(s3);

    print(v);
}    

void Run_1_EmplaceBack() {
    std::vector<mystring> v;

    v.reserve(3);

    mystring s("hello");
    v.emplace_back(s);

    mystring s2("world");
    v.emplace_back(s2);

    mystring s3("!");
    v.emplace_back(s3);

    print(v);
} 

void Run_1_StdMove() {
    std::vector<mystring> v;

    v.reserve(3);

    mystring s("hello");
    v.emplace_back(std::move(s));

    mystring s2("world");
    v.emplace_back(std::move(s2));

    mystring s3("!");
    v.emplace_back(std::move(s3));

    for (const mystring& x : v) {  
        std::cout << x.s << " ";
    }
} 
