//https://app.asana.com/1/656176460444/project/1208315729461187/task/1209655350170893

#include <iostream>
#include "Task-1-2.h"

void Run_2(){
    int a = 777;
    std::cout << "создаем int a = 777 (4 byte)\n"; 
    int b = 666;
    std::cout << "создаем int b = 666 (4 byte), по идее должен идти в стеке сразу за a\n"; 
    int *c = &b; 
    std::cout << "создаем указатель c, который хранит адрес b в памяти\n"; 
    
    std::cout << *(c+1) << std::endl;
    std::cout << "к адресу плюсуем единицу, что говорит о том, что он должен указывать на следующий int в памяти, а это наша b (теоретически, гугл говорит что это UB) \n"; 
}