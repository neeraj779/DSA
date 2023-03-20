#include <iostream>
#include <vector>
using namespace std;
void subSequence(int arr[], int n, int s, vector<int> &v, int i, int sum)
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
        }
        return;
    }

    // pick the particular element in subsequence
    v.push_back(arr[i]);
    sum += arr[i];
    subSequence(arr, n, s, v, i + 1, sum);

    v.pop_back();
    sum -= arr[i];

    // don't pick the particular element in subsequence
    subSequence(arr, n, s, v, i + 1, sum);
}
int main()
{
    int arr[] = {3, 1, 2};
    vector<int> v;
    subSequence(arr, 3, 3, v, 0, 0);
    return 0;
}