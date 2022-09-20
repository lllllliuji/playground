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


    /*
        width-histogram: [0, 10] = 100, [11, 20] = 200, [21, 30] = 500, ....
        depth-histogram  20, 40, 60, 70 most frequent value = 22, 30 , 40
        catalog:
            n(r) / distinct(v) is used to estimate the result lines
        historgram:
        select:
            nr * s1 * s2 * s3 * ... * s(x) / (nr) ^ x
        sample estimate: relation 取样 -> 估计
        p = 1 - (1 - s1 / nr) * (1 - s2 / nr) * (1 - s3 / nr) ****
        s = nr * p


        join
        Cartesian product: R join S, nr * ns * lr * ls
        R & S = null, same as Cartesian
        R intersection(key) S = X, ns * ls (R's key is used as filter)
        is not key: nr * ns / distinct(R) or nr * ns / distinct(s)

        histogram
            range_size * range_size / distinct(range)
        select id = t; esitmated size = nr * lr * (distinct(id)) / lr
        select id < t; estimated size = nr * lr * (t - min) / (max - t)
        histogram:

        expression E -> all equivlent E -> explore all ? or heuristics 先做选择、投影
        estimeate size  
        algorithm   
        pipeline
        a join b join c
        (a join c) join b
        (a join b) join c
        (b join c) join a
        阶乘式的增长的
        Set<E> 

        递归：
        f[Set] = min(Set, f[subset] + f[Set - subset] + cost A);
        costA 代表采用不同的algorithm计算
    */
    return 0;
}
