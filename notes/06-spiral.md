## 06-spiral

- Input:
  - Number of test cases t
  - For each test case: row r and column c
- Output:

  - The number at position (r, c) in a spiral-filled grid

- 5 layers of the spiral grid
  
<img width="440" height="365" alt="image" src="https://github.com/user-attachments/assets/b22e86f1-54b9-4885-b412-a405b429788e" />

```
Input:
3
2 3
1 1
4 2

Output:
8
1
7
```

### Learnings

- Couldn't understand the question or how input and output are working.
- Couldn't identify the pattern.
  - Identified the pattern through [Mike the Coder's Number Spiral Video](https://www.youtube.com/watch?v=MlwnifQvs8M)
- After identifying the pattern, coding was easy.
- Learning while coding
  - First line = number of test cases, then pairs of coordinates (Took 3 attempts to finally understand what the input is)
  - Use long long for all variables (large coordinates cause overflow)
  - Read r, c inside the loop for each test case
  - **NOTE: Understand the input and output properly**

### My Approach (Pattern) (Not on my own)

**For diagonal elements**

<img width="1266" height="391" alt="image" src="https://github.com/user-attachments/assets/48fecf33-d6ba-488f-a35e-450478f118f4" />

**For elements where r>c**

<img width="1291" height="372" alt="image" src="https://github.com/user-attachments/assets/4db5e011-c214-4b59-80c3-6605bee152a2" />

**For elements where c>r**

<img width="1273" height="381" alt="image" src="https://github.com/user-attachments/assets/33fda176-7ba7-4f27-b3b1-5a4db065fd9b" />

<img width="524" height="162" alt="image" src="https://github.com/user-attachments/assets/cc76cfd5-f7ae-42ca-a1a5-dff73045c166" />

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    while (n--)
    {
        long long r, c;
        cin >> r >> c;

        long long result;

        if (c == r)
        {
            result = r * c - (r - 1);
        }
        else if (c > r)
        {
            if (c % 2 == 0)
            {
                long long diagonal = c * c - (c - 1);
                result = diagonal - (c - r);
            }
            else
            {
                long long diagonal = c * c - (c - 1);
                result = diagonal + (c - r);
            }
        }
        else
        {
            if (r % 2 == 0)
            {
                long long diagonal = r * r - (r - 1);
                result = diagonal + (r - c);
            }
            else
            {
                long long diagonal = r * r - (r - 1);
                result = diagonal - (r - c);
            }
        }

        cout << result << "\n";
    }

    return 0;
}
```
