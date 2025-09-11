## 02-missing-number

- Input: n (the full range 1..n), and n-1 numbers.
- Exactly one number is missing.
- Need: Print the missing number.

### **Learnings**

- How to use C++ `vector`
- Techniques to find a missing element:
  - Summation Trick (using arithmetic formula)
  - XOR Trick
  - Sorting Trick
- The trade-off between time and space complexity
- In contests, go for the summation or XOR approach immediately — they're fast and safe.
- Avoid unnecessary storage if you only need aggregates like sum or XOR.
- Always be alert for overflow when dealing with n(n+1)/2 — use long long or 1LL _ n _ (n + 1).

### My approach - brute force

- Loop through numbers from `1` to `n`.
- For each, check if it's present in the input using `std::find`.
- Time complexity:
  - `O(n)` for each `find` × `n` iterations = `O(n²)`
- Space complexity:
  - `O(n)` to store input in a `vector`.

```cpp
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
```

- Fails for large n (e.g., 200000) due to time complexity.

### Summation Formula (O(n))

- Sum of numbers 1..n can be computed in O(1) with the formula:
  $$S = \frac{n(n+1)}{2}$$
- Then subtract the sum of all given numbers.
- The difference is the missing number.
- **Complexity**: O(n) time, O(1) space.

- After learning about this approach, I did the following.

**Optimized Time Complexity**

```cpp
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
```

- But this can be optimized as I don't need to store numbers for comparison, I just have to store the sum.
- So for his approach, time complexity becomes O(n) but space complexity remains O(n)

**Optimized Space Complexity**

```cpp

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
```

### XOR Trick

- XOR all numbers from 1..n.
- XOR again with all given numbers.
- **Since duplicates cancel out, the result is the missing number**.
- Complexity: O(n) time, O(1) space.
- This avoids large integer sums if n is very big.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int xor_all = 0;
    int xor_input = 0;

    for (int i = 1; i <= n; i++)
    {
        xor_all ^= i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        xor_input ^= x;
    }

    cout << (xor_all ^ xor_input);

    return 0;
}
```

### Sorting (O(n log n))

- Sort the vector.
- Walk through and find the first gap.
- Complexity: O(n log n), but still fast enough for 200k.
