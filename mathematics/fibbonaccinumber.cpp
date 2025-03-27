//large value of n so fast computing logn
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
    long long m[2][2];
};

// Multiplies two 2x2 matrices under modulo
Matrix multiply(Matrix a, Matrix b) {
    Matrix res;
    res.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % MOD;
    res.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % MOD;
    res.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % MOD;
    res.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % MOD;
    return res;
}

// Fast exponentiation of the matrix
Matrix power(Matrix base, long long exp) {
    Matrix res = {1, 0, 0, 1};  // Identity matrix
    while (exp > 0) {
        if (exp % 2) res = multiply(res, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}

// Function to compute Fibonacci number F(n)
long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix base = {1, 1, 1, 0};
    Matrix result = power(base, n - 1);
    return result.m[0][0];  // F(n) is stored in the top-left element
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}
