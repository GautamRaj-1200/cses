#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum_of_n = 1LL * n * (n + 1) / 2;
    long long sum_of_inputs = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        sum_of_inputs += x;
    }

    cout << sum_of_n - sum_of_inputs;
    return 0;
}
