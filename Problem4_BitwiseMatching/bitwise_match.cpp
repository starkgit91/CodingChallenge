// C++ implementation for Bitwise Matching Pattern
#include <bits/stdc++.h>
using namespace std;
int nextWithSameOnes(int n) {
    int c = n, c0 = 0, c1 = 0;

    while ((c & 1) == 0 && c != 0) { c0++; c >>= 1; }
    while ((c & 1) == 1) { c1++; c >>= 1; }

    if (c0 + c1 == 31 || c0 + c1 == 0) return -1;

    int p = c0 + c1;
    n |= (1 << p);
    n &= ~((1 << p) - 1);
    n |= (1 << (c1 - 1)) - 1;

    return n;
}

int main() {
    int n = 13948; // Binary: 11011001111100
    cout << "Next number with same set bits: " << nextWithSameOnes(n) << endl;
    return 0;
}
