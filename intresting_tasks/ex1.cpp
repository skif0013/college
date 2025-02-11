#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) { 
            for (int c = b; c <= n; c++) {  
                if (a * a + b * b == c * c) {
                    std::cout << a << " " << b << " " << c << std::endl;
                }
            }
        }
    }
    return 0;
}