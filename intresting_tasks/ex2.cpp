#include <iostream>

void pascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        int* row = new int[i + 1]; 
        row[0] = row[i] = 1; 

        for (int j = 1; j < i; j++) {
            row[j] = row[j - 1] * (i - j + 1) / j;
        }

        for (int j = 0; j <= i; j++) {
            std::cout << row[j] << " ";
        }
        std::cout << std::endl;

        delete[] row;
    }
}

int main() {
    int n;
    std::cin >> n;
    pascalTriangle(n);
    return 0;
}