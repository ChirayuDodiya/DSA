#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Sieve of Eratosthenes to find all prime numbers up to n
    vector<int> sieve(int n)
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
                primes.push_back(i);
        }

        return primes;
    }
};

int main()
{
    Solution s;
    int n = 30;
    vector<int> ans = s.sieve(n);

    cout << "Prime numbers up to " << n << ": ";
    for (int prime : ans)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
