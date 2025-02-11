#include <iostream>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void findTwinPrimes(int n) {
    for (int i = n; i <= 2 * n - 2; ++i) {
        if (isPrime(i) && isPrime(i + 2)) {
            std::cout << "(" << i << ", " << i + 2 << ")\n";
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    findTwinPrimes(n);

    return 0;
}
// abc