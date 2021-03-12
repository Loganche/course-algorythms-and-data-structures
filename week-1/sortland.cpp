#include "edx-io.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    double x[9999];
    double x_clone[9999];
    int n;

    io >> n;

    for (int i = 0; i < n; i++)
    {
        io >> x[i];
        x_clone[i] = i + 1;
    }

    /*
    //test
    for (auto c : x)
        io << c << " ";
    io << '\n';
    for (auto c : x_clone)
        io << c << " ";
    io << '\n';*/

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && x[j - 1] > x[j]; j--)
        {
            swap(x[j - 1], x[j]);
            swap(x_clone[j - 1], x_clone[j]);
        }
    }

    /*
    //test
    for (auto c : x)
        io << c << " ";
    io << '\n';
    for (auto c : x_clone)
        io << c << " ";
    io << '\n';*/

    double poor = x_clone[0], middle = x_clone[n / 2], rich = x_clone[n - 1];
    //io << poor << " " << middle << " " << rich << '\n';

    io << poor << " " << middle << " " << rich;

    return 0;
}