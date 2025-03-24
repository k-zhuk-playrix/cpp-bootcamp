//https://app.asana.com/0/1208315729461187/1209698562312859
#include <functional>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

int globalResourceCount = 0;

class Resource {
    std::string name;
public:
    Resource(const std::string& n) : name(n) {
        std::cout << "Resource " << name << " created\n";
        globalResourceCount++;
    }
    ~Resource() {
        std::cout << "Resource " << name << " destroyed\n";
        globalResourceCount--;
    }
    std::string getName() const { return name; }
};

//тут все оки
void printNameStack() {
    Resource resource("Stack");
    std::cout << "Resource name: " << resource.getName() << std::endl;
}

void printNameHeap() {
    //fixed with unique
    auto resource = std::make_unique<Resource>("Heap");
    std::cout << "Resource name: " << resource->getName() << std::endl;
}

std::function<void()> getPrintNameFunction() {
    //fixed with shared
    auto resource = std::make_shared<Resource>("Heap in lambda");

    return [resource]() {
        std::cout << "Resource name: " << resource->getName() << std::endl;
    };
}

void printResourceNames(std::vector<std::shared_ptr<Resource>>& resources) {
    for (const auto& resource  : resources) {
        std::cout << "Resource name: " << resource->getName() << std::endl;
    }
}

//прячем в метод, чтобы очистилось после выхода из зоны видимости
void printResources(){
    std::vector<std::shared_ptr<Resource>> resources;
    resources.push_back(std::make_shared<Resource>("Resource 1"));
    resources.push_back(std::make_shared<Resource>("Resource 2"));
    resources.push_back(std::make_shared<Resource>("Resource 3"));
    printResourceNames(resources);
}

int Run_2_1() {
    printNameStack();
    printNameHeap();
    getPrintNameFunction()();
    printResources();

    std::cout << std::endl << "Global used resources count: " << globalResourceCount << std::endl;
    return 0;
}