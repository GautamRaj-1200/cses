#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void missing_number(long long n, vector<long long> nums)
{
    for (long long i = 1; i <= n; i++)
    {
        if (find(nums.begin(), nums.end(), i) == nums.end())
        {
            cout << i;
            return;
        }
    }
}

int main()
{
    long long n;
    cin >> n;

    vector<long long> nums;

    for (long long i = 0; i < n - 1; i++)
    {
        long long x;
        cin >> x;
        nums.push_back(x);
    }

    missing_number(n, nums);
    return 0;
}
