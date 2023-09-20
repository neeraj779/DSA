#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void helperMergeSort(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid)
        {
            temp.push_back(nums[left++]);
        }

        while (right <= high)
        {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; ++i)
        {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        helperMergeSort(nums, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> res(nums);
        mergeSort(res, 0, res.size() - 1);
        return res;
    }
};

int main()
{

    Solution ob = Solution();
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> res = ob.sortArray(nums);
    for (auto i : res)
        cout << i << " ";
    return 0;
}