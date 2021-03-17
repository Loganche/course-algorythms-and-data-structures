#include "edx-io.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    io >> n;

    int *x = new int[n];
    for (int i = 0; i < n; i++)
    {
        io >> x[i];
    }

    return 0;
}