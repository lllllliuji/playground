#ifndef test_h_
#define test_h_
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <thread>
#include <future>
#include <tuple>
#include <list>
#include <unordered_map>
#include "complex.h"
#include "friend.h"
#include "strvec.h"
#include "base.h"

template <typename T>
int compare(const T& v1, const T& v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return  strcmp(p1, p2);
}

template <typename T>
void my_swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}
#endif