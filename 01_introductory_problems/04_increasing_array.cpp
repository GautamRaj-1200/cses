#include <iostream>
#include <vector>
using namespace std;

void increasing_array_moves(int n, vector<int> &nums)
{
    long long count = 0;
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            int cost = nums[i] - nums[i + 1];
            nums[i + 1] += cost;
            count += cost;
        }
    }
    cout << count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    increasing_array_moves(n, nums);
    return 0;
}
