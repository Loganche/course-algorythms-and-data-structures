#include "edx-io.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    io >> n;
    int max = INT32_MIN;
    int max_pos = 0;
    int min = INT32_MAX;
    int min_pos = 0;

    int *x = new int[n];

    for (int i = 0; i < n; i++)
    {
        io >> x[i];

        if (x[i] < min)
        {
            min = x[i];
            min_pos = i;
        }
        if (x[i] > max)
        {
            max = x[i];
            max_pos = i;
        }
    }

    if (min_pos > 0)
    {
        swap(x[min_pos], x[0]);
        io << "Swap elements at indices " << 1 << " and " << min_pos + 1 << ".\n";
    }
    if (max_pos == 0)
        max_pos = min_pos;
    if (max_pos < n - 1)
    {
        swap(x[max_pos], x[n - 1]);
        io << "Swap elements at indices " << max_pos + 1 << " and " << n << ".\n";
    }

    for (int i = 2; i < n - 1; i++)
    {
        for (int j = i - 1; x[j] > x[j + 1]; --j)
        {
            int k = j;
            while (x[k] > x[j + 1])
            {
                k--;
                if (k == 0)
                    break;
            }
            swap(x[k + 1], x[j + 1]);
            io << "Swap elements at indices " << k + 2 << " and " << j + 2 << ".\n";
            j = k + 1;
        }
    }

    io << "No more swaps needed.\n";
    for (int i = 0; i < n; ++i)
        io << x[i] << ' ';

    return 0;
}

/*#include <fstream>
using namespace std;

void insertcoutnsort(int n, int *m, std::ofstream &fout)
{
    int i, j, temp, x, y, k;

    for (j = 1; j < n; ++j)
    {
        for (i = j - 1; i >= 0 && m[i] > m[i + 1]; --i)
        {
            k = i;
            while (m[k - 1] >= m[k])
            {
                k--;
                if (k == 0)
                    break;
            }

            temp = m[i + 1];
            m[i + 1] = m[k];
            m[k] = temp;
            fout << "Swap elements at indices " << k + 1 << " and " << i + 2 << ".\n";
            i = k;
        }
    }
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;

    int *m = new int[n];

    for (int i = 0; i < n; ++i)
        fin >> m[i];

    insertcoutnsort(n, m, fout);

    fout << "No more swaps needed.\n";

    for (int i = 0; i < n; ++i)
        fout << m[i] << ' ';
    fout << '\n';

    delete[] m;

    return 0;
}*/