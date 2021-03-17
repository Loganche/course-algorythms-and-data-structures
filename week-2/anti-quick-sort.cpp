#include "edx-io.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    io >> n;

    for (int i = n; i > 0; --i)
    {
        io << i << " ";
    }

    return 0;
}
