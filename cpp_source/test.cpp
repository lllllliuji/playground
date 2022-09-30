#include "test.h"
long qmi(long a, long b, long mod) {
    long ans = 1;

    while (b) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main() {
    
    std::list<int> li;
    for (int i = 0; i < 10; i++) li.emplace_back(i);
    
    std::hash<std::string> h = std::hash<std::string>();
    std::cout << h(std::string("hello world")) << std::endl;
    std::cout << h(std::string("hello world!")) << std::endl;

    return 0;
}
