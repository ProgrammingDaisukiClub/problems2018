#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for(int i=0; i<t; i++) {
        int a, b;
        std::cin >> a >> b;
        int ans = a * b;
        std::cout << ans << std::endl;
    }
}
