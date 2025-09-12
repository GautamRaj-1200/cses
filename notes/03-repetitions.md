## 03-repetitions

Input: A DNA sequence string consisting of characters A, C, G, and T.
Output: Print the length of the longest substring where all characters are the same.
Rule: A repetition is defined as consecutive identical characters in the string.

```
Input:  ATTCGGGA
Output: 3
```

## **Learnings**

- String input in C++: read directly using cin >> dna_sequence;.
- We can iterate string the same as a vector
- Should have started the count & max count from 1 not 0. (Since a single character already forms a repetition of length 1.)
- While comparing consecutive elements - watch out for overflow
  - Always start from index 1 and compare with i - 1 to avoid going out of bounds.
- Type of .size()
  - size() returns size_t → an unsigned integer type (unsigned long or unsigned long long, platform-dependent).
  - Comparing int i with size_t results in a signed/unsigned mismatch warning.
  - Best practice: use size_t for the loop variable if only used for indexing.

```c++
for(int i=0; i<s.size();i++){} // this gives a warning - Because we’re comparing a signed int (i) with an unsigned size_t (v.size()).
```

### My approach

- Iterate through the string
- Compare the consecutive elements
- If same - increase the count
- If not - reset count = 1
- Update max_count = max(max_count, count) each step.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

void repetitions(string dna_sequence)
{
    int max_count = 1;
    int count = 1;

    for (size_t i = 1; i < dna_sequence.size(); i++)
    {
        if (dna_sequence[i] == dna_sequence[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        max_count = max(max_count, count);
    }

    cout << max_count;
}

int main()
{
    string dna_sequence;
    cin >> dna_sequence;
    repetitions(dna_sequence);
    return 0;
}
```
