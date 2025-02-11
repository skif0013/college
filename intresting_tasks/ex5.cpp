#include <iostream>

bool isPalindrome(int num) {
    int rev = 0, temp = num;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return num == rev;
}

int main() {
    int n;
    std::cin >> n;

    bool res = isPalindrome(n);
    
    std::cout << res << std::endl;
    
    return 0;
}