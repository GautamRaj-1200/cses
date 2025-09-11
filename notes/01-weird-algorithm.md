## 01-weird-algorithm

- Input: A single integer n representing the starting value of the sequence.
- Output: Print the full Collatz sequence starting from n and ending at 1, following the rules below.
- Rules (Collatz sequence):
  - If n is even, the next number is n / 2.
  - If n is odd, the next number is n \* 3 + 1.
  - Repeat this until n becomes 1.
- Output all values in the sequence, including the initial value and the final 1.

### **Learnings**

- Got a **TLE (Time Limit Exceeded)** due to using `int` — overflow caused an infinite loop.
- For sequences with potentially large values, use `long long` instead of `int`.
- Missed printing the last value (`1`) initially — need to handle it after the loop.
- This problem is based on the **Collatz sequence** — useful to recognize such patterns in future problems.

### My approach

```cpp
void weird(int n){
    while(n > 1){
        cout << n << " ";
        if(n % 2 == 0){
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << n;
}
```

- Absolutely correct.
- But **TTL** for large numbers.

### Better approach using **long**

```cpp
#include <iostream>
using namespace std;
void weird(long long n){
    while(n > 1){
        cout << n << " ";
        if(n % 2 == 0){
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << n;
}
```

- This avoids overflow, preventing TLE.
- Works correctly for all valid input within the problem constraints.

### Time Complexity

- O(log n) for the Collatz sequence (approximate average case).
- Worst case not proven, but empirically small for n ≤ 10⁶.

### Edge Cases Considered

- Input = 1 → should just print `1`.
- Input = large odd numbers → check for overflow.
