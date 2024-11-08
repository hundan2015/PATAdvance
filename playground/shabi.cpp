#include <iostream>
using namespace std;
template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

int main() {
    int result = sum(1, 2, 3, 4);
    cout << result;
}