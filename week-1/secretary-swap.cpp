#include <iostream>
#include "edx-io.hpp"

void megasort(int n, int *x)
{
    int k, i, j, temp;
    for (j = 1; j < n; ++j)
    {
        for (i = j - 1; i >= 0 && x[i] > x[i + 1]; --i)
        {
            k = i;
            while (x[k - 1] >= x[k])
            {
                k--;
                if (k == 0)
                    break;
            }

            temp = x[i + 1];
            x[i + 1] = x[k];
            x[k] = temp;
            io << "Swap elements at indices " << k + 1 << " and " << i + 2 << ".\n";
            i = k;
        }
    }
}

int main()
{

    int n;
    io >> n;

    int *x = new int[n];

    for (int i = 0; i < n; ++i)
        io >> x[i];

    megasort(n, x);

    io << "No more swaps needed.\n";

    for (int i = 0; i < n; ++i)
        io << x[i] << ' ';
    io << '\n';

    delete[] x;

    return 0;
}