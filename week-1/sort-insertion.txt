#include "edx-io.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long x[1000];
    int y[1000];
    int n;

    io >> n;

    for (int i = 0; i < n; i++)
    {
        io >> x[i];
        y[i] = 0;
    }

    y[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int k = 0;
        for (int j = i; j > 0 && x[j - 1] > x[j]; j--)
        {
            swap(x[j - 1], x[j]);
            k++;
        }
        y[i] = i - k + 1;
        k = 0;
    }

    for (int i = 0; i < n; i++)
    {
        io << y[i] << " ";
    }
    io << '\n';
    for (int i = 0; i < n; i++)
    {
        io << x[i] << " ";
    }

    return 0;
}