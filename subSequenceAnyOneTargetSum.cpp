#include <iostream>
#include <vector>
using namespace std;
int subSequence(int arr[], int n, int s, vector<int> &v, int i, int sum)
{
    if (i == n)
    {
        if (sum == s)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // pick the particular element in subsequence
    v.push_back(arr[i]);
    sum += arr[i];
    if (subSequence(arr, n, s, v, i + 1, sum))
        return true;

    v.pop_back();
    sum -= arr[i];

    // don't pick the particular element in subsequence
    if (subSequence(arr, n, s, v, i + 1, sum))
        return true;
    return false;
}
int main()
{
    int arr[] = {3, 1, 2};
    vector<int> v;
    subSequence(arr, 3, 2, v, 0, 0);
    return 0;
}