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