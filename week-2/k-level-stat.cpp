#include "../edx-io.hpp"
#include <iostream>
#include <vector>

using namespace std;

int partition(int *&mas, int left, int right)
{
    if (left != right)
        swap(mas[left + rand() % (right - left)], mas[right]);
    int x = mas[right];
    int i = left - 1;
    for (int j = left; j <= right; j++)
    {
        if (mas[j] <= x)
            swap(mas[++i], mas[j]);
    }
    return i;
}

int nth(int *mas, int k, int size)
{
    int left = 0, right = size - 1;
    for (;;)
    {
        int pos = partition(mas, left, right);
        if (pos < k)
            left = pos + 1;
        else if (pos > k)
            right = pos - 1;
        else
            return mas[k];
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

    for (int i = nth(arr, arr[k1], n); i < k2; i++)
        cout << arr[i] << " ";
    return 0;
}

/*
int partition(vector<int> &mas, int l, int r) {
  if (l!=r)
    swap(mas[l + rand() % (r - l)], mas[r]);
  int x = mas[r];
  int i = l-1;
  for (int j = l; j <= r; j++) {
    if (mas[j] <= x)
      swap(mas[++i],mas[j]);
  }
  return i;
}
int nth(vector<int> mas, int n) {
  int l = 0, r = mas.size() - 1;
  for(;;) {
    int pos = partition(mas,l,r);
    if (pos < n)
      l = pos + 1;
    else if (pos > n)
      r = pos - 1;
    else return mas[n];
  }
}
*/