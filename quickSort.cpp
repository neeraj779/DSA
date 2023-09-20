#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[low];
    int i = low, j = high;

    while (i < j)
    {
        while (nums[i] <= pivot && i <= high - 1)
            i++;
        while (nums[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int partIndex = partition(nums, low, high);
        quickSort(nums, low, partIndex - 1);
        quickSort(nums, partIndex + 1, high);
    }
}

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};
    quickSort(nums, 0, nums.size() - 1);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}