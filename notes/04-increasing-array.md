## 04-increasing-array

- Input: An integer n (array size), followed by n integers.
- Output: Print the minimum number of moves required to make the array non-decreasing.
- Rule: In one move, you can increase any element by 1.

```
Input:
5
3 2 5 1 7

Output:
5
```

- Make 2 → 3 → cost 1
- 5 is fine after 3
- Make 1 → 5 → cost 4
- 7 is fine after 5
- Total = 1 + 4 = 5

### Learnings

- Couldn't understand question properly : Understood using ChatGPT
- Fixed-size vector input. In C++, we can create a fixed-size vector at runtime with: `vector<int> nums(n);`
  - This allocates a vector of size n with default values (0 for int).
  - Then we can take input in a loop: `for (int i = 0; i < n; i++) cin >> nums[i];`
- **Approach Learned(Not on my own)**
- Use `long long` for counting moves, since the sum of differences can exceed int range.
- Start the loop from i = 0 up to i < nums.size() - 1 to avoid out-of-bounds when checking nums[i+1].
- Pass the vector by reference (vector<int>& nums) so we don’t make an unnecessary copy.

### My Approach - Not on my own

- Iterate from left to right.
- Compare each nums[i] with nums[i+1].
- If nums[i] <= nums[i+1], continue.
- If nums[i] > nums[i+1], increase nums[i+1] by nums[i] - nums[i+1].
- Add the same difference to the total count.
- After the loop, count holds the minimum number of moves.

```cpp
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
```
