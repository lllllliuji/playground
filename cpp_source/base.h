#include <iostream>
#include <memory>
#pragma once

class base {
   private:
    int r;
    int c;
    int *data;

   public:
    void print();
    base(int r, int c);
    virtual ~base();
    static void hello();
    int getRows() { return r; }
    int getColumns() { return c; }
    int getElem(int i, int j) { return data[i * c + j]; }
    void setElem(int i, int j, int val) { data[i * c + j] = val; }
    void init();
};
void base::init() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            data[i * c + j] = std::rand() % 10;
        }
    }
}
void base::hello() { std::cout << "hello" << std::endl; }
base::base(int r_, int c_) : r(r_), c(c_), data(nullptr) {
    data = new int[r * c];
    init();
}
base::~base() { delete[] data; }
void base::print() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << data[i * c + j] << " ";
        }
        std::cout << std::endl;
    }
}
std::unique_ptr<base> add(std::unique_ptr<base> t1, std::unique_ptr<base> t2) {
    auto ret = std::make_unique<base>(t1->getRows(), t1->getColumns());
    for (int i = 0; i < t1->getRows(); i++) {
        for (int j = 0; j < t1->getColumns(); j++) {
            ret->setElem(i, j, t1->getElem(i, j) + t2->getElem(i, j));
        }
    }
    return ret;
}
class derived : public base {
   public:
    void dhello() { std::cout << "hello" << std::endl; }
    derived(int r, int c): base(r, c) {}
};
void derived_test() {
    std::unique_ptr<base> ptr = std::make_unique<derived>(3, 3);
    auto dptr = dynamic_cast<derived*> (ptr.get());
    dptr->dhello();
}
void base_test() {
    auto ptr = std::make_unique<base>(5, 5);
    ptr->print();
    std::cout << std::endl;
    auto ptr2 = std::make_unique<base>(5, 5);
    ptr2->print();
    std::cout << std::endl;
    auto result = add(std::move(ptr), std::move(ptr2));
    result->print();
}