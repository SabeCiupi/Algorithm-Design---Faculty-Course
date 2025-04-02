#include <iostream>

using namespace std;

long long power(long long x, int n) {
    if (n == 0) return 1;
    long long half = power(x, n/2);
    if(n%2 == 0) return half*half;
    else return x * half * half;
}

int main() {
    int x = 2;
    int n = 4;

    cout << power(x, n) << endl;

    return 0;
}