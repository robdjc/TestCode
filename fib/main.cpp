#include <iostream>

// 0, 1, 1, 2, 3, 5, 8, 13, 21

void fibonacci(int n) {
    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << " ";
    }
}


int main() {
    std::cout << "fibonacci test" << std::endl;

    fibonacci(5);

    return 0;
}