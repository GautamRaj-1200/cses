## 05-permutations

- Input: An integer n.
- Output: A permutation of numbers 1...n such that no two adjacent numbers differ by 1. If not possible, print "NO SOLUTION".

```
Input:
5

Output:
2 4 1 3 5
```

### Learnings

- Understood the condition: adjacent numbers should not differ by 1.
- Special cases: n = 2 or n = 3 → No solution exists.
- Found the constructive trick myself:
  - Print even numbers first, then odd numbers.
  - This ensures all differences are ≥ 2 for n ≥ 4.
- However, even numbers must be printed first. Otherwise, if we print ODD numbers first, then, in the case of 4, the output becomes 1 3 2 4 -> 3 and 2 have a difference of 1.

### My Approach

- If n = 1: print 1.
- If n = 2 or 3: print "NO SOLUTION".
- Else:
  - Loop i = 2 to n, step 2 → print evens.
  - Loop i = 1 to n, step 2 → print odds.

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    if (n > 1 && n < 4)
    {
        cout << "NO SOLUTION";
    }

    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                cout << i << " ";
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                cout << i << " ";
            }
        }
    }

    return 0;
}
```
