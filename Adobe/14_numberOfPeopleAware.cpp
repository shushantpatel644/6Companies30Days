class Solution
{
private:
    int mod = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<long long> persons(n + 1, 0);
        persons[1] = 1;
        // persons[i] sharing th escret at day i

        long long numberOfPeoplesharingscret = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i - delay >= 0)
                numberOfPeoplesharingscret = (numberOfPeoplesharingscret + persons[i - delay]) % mod;

            if (i - forget >= 0)
                numberOfPeoplesharingscret = (numberOfPeoplesharingscret - persons[i - forget] + mod) % mod;

            persons[i] = numberOfPeoplesharingscret;
        }

        // add all persons who are not forgotten the secret
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++)
        {
            ans = (ans + persons[i]) % mod;
        }
        return ans;
    }
};