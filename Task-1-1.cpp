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
    //создается пустой вектор стрингов
    std::vector<mystring> v;

    //выделяется память под новую строку s1
    mystring s("hello");
    //создается новая mystring, тк s1 передается не по указателю, помещается в вектор
    //у вектора выделяется память под новый объект
    v.push_back(s);

    //выделяется память под новую строку s2
    mystring s2("world");    
    //создается новая mystring, тк s2 передается не по указателю, помещается в вектор
    //у вектора выделяется память под новый объект, все старые объекты копируются в новую структуру
    v.push_back(s2);

     //выделяется память под новую строку s3
    mystring s3("!");
    //создается новая mystring, тк s3 передается не по указателю, помещается в вектор
    //у вектора выделяется память под новый объект, все старые объекты копируются в новую структуру еще раз :) 
    v.push_back(s3);

    //пробегаемся по каждому элементу вектора, опять копируем строки 
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
