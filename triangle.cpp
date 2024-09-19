#include <iostream>

void print_triangle(unsigned int n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < i + 1; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    for (unsigned int i = n; i > 1; i--) {
        for (unsigned int j = 1; j < i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Введите длину высоты треугольника: ";
    unsigned int n;
    std::cin >> n;
    print_triangle(n);
}