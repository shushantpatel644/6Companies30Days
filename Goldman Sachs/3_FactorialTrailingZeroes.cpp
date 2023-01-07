class Solution
{
public:
    int trailingZeroes(int n)
    {
        // iterative
        int count = 0;

        for (int i = 5; i <= n; i = i * 5)
        {
            count = count + n / i;
        }
        return count;
    }
    // recursive
    // return (n != 0) ? n / 5 + trailingZeroes(n / 5) : 0;
};
//
/* Time Complexity: O(log n)
we have the 5^k <=n
∴ 5^k = n
k = log n base 5
Space Complexity: O(1)*/