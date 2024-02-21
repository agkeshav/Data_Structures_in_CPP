// Find count of prime numbers strictly less than n
// Approach
// Mark every number as prime Number
// Jo jo table mein aa rha hai use non prime mark kr do
#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
        }
        for (int j = 2 * i; j < n; j = j + i)
        {
            prime[j] = false;
        }
    }
    return (cnt);
}
int main()
{
    cout << "Enter the number" << endl;
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;
    return 0;
}