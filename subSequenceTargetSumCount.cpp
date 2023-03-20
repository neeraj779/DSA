#include <iostream>
#include <vector>
using namespace std;
int a = 0;
int subSequence(int arr[], int n, int i, int s, int sum)
{
    // strictly done for positive numbers only
    if (sum > s)
        return 0;

    if (i == n)
    {
        if (sum == s)
            return 1;
        return 0;
    }

    // pick the particular element in subsequence
    sum += arr[i];
    int l = subSequence(arr, n, i + 1, s, sum);

    sum -= arr[i];

    // don't pick the particular element in subsequence
    int r = subSequence(arr, n, i + 1, s, sum);
    return l + r;
}
int main()
{
    int arr[] = {3, 1, 2};
    cout << subSequence(arr, 3, 0, 3, 0);
    return 0;
}