#include <iostream>



void sieve(int n) {
    bool* prime = new bool[n + 1];
    for (int i = 2; i <= n; i++) prime[i] = true;  

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int j = p * p; j <= n; j += p) {
                prime[j] = false;  
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i]) std::cout << i << " ";
    }
    std::cout << std::endl;

    delete[] prime;  
}

int main() {
    sieve(1000);
    return 0;
}