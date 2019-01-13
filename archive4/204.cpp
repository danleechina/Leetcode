#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
bool myfunction(int i, int j) { return (i < j); }

class Solution
{
  public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<int> primes = {2};
        for (int i = 3; i < n; i++)
        {
            bool isPrime = true;
            double s = sqrt(i);
            for (auto p : primes)
            {
                if (i % p == 0)
                {
                    isPrime = false;
                    break;
                }
                if (p > s)
                    break;
            }
            if (isPrime)
                primes.push_back(i);
        }
        return primes.size();
    }
};