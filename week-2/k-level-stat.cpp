#include "../edx-io.hpp"
#include <iostream>

using namespace std;

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void printKnums(int *array, int k1, int k2)
{
    for (int i = k1; i <= k2; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void quickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int findOrderStatistic(int *array, int k, int n)
{
    int left = 0, right = n;
    int mid = array[(left + right) / 2];
    while (true)
    {

        if (mid == k)
        {
            return mid;
        }
        else if (k < mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    //input
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    if (k2 - k1 >= 200)
        return 0;

    int *arr = new int[n];
    int A, B, C;
    cin >> A >> B >> C >> arr[0] >> arr[1];

    for (int i = 2; i < n; i++)
    {
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
    }

    int knum = findOrderStatistic(arr, arr[k1], n);

    printArray(arr, n);

    printKnums(arr, knum, k2);

    return 0;
}
