#include "edx-io.hpp"

int main() {
    long long a, b;
    io >> a >> b;
    io << a + b * b << '\n';
    return 0;
}