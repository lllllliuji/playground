#pragma once

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