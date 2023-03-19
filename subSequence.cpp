#include <iostream>
#include <vector>
using namespace std;
void subSequence(int arr[], int n, vector<int> &v, int i = 0)
{
    if (i == n)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // if (v.size() == 0)
    //     cout << "{} " << endl;

    // pick the particular element in subsequence
    v.push_back(arr[i]);
    subSequence(arr, n, v, i + 1);

    v.pop_back();
    // don't pick the particular element in subsequence
    subSequence(arr, n, v, i + 1);
}
int main()
{
    int arr[] = {3, 1, 2};
    vector<int> v;
    subSequence(arr, 3, v, 0);
    return 0;
}