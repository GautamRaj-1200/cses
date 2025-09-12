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
