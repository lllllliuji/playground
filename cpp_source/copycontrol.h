#include <iostream>
#include <memory>
#include <vector>
class A {
private:
    std::shared_ptr<std::vector<int>> p;
    
public:
    A() = default;
    A(const A &a);
    A& operator= (const A&);
    A& operator= (A&&);
    ~A();
};