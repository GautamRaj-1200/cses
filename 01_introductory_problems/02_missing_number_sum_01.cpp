#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void missing_number(long long n, vector<long long> nums)
{
    long long sum_of_n = (n * (n + 1)) / 2;
    long long sum_of_n_minus_1 = 0;

    for (long long i = 0; i < nums.size(); i++)
    {
        sum_of_n_minus_1 += nums[i];
    }
    cout << sum_of_n - sum_of_n_minus_1;
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
